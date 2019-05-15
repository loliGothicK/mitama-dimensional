#ifndef MITAMA_DIMENSIONAL_DIMENSIONAL_TRAITS_HPP
#define MITAMA_DIMENSIONAL_DIMENSIONAL_TRAITS_HPP
#include <dimensional/fwd/quantity_fwd.hpp>
#include <dimensional/fwd/units_fwd.hpp>
#include <dimensional/fwd/dimensional_fwd.hpp>
#include <dimensional/mitamagic/type_traits_ext.hpp>
#include <dimensional/mitamagic/type_list.hpp>
#include <type_traits>
#include <dimensional/mitamagic/quotient.hpp>

namespace mitama {
    // quantity_t traits
    template <class T> struct is_quantity : std::false_type {};

    template <class D, class T>
    struct is_quantity<quantity_t<D, T>> : std::true_type {};

    template <class T> inline constexpr bool is_quantity_v = is_quantity<T>::value;

    // units_t traits
    template <class> struct is_units : std::false_type {};

    template <class D, class E, class S>
    struct is_units<units_t<D, E, S>> : std::true_type {};

    template <class U> inline constexpr bool is_units_v = is_units<U>::value;

    // dimensional_t traits
    template <class> struct is_dimensional : std::false_type {};

    template <template <class> class Synonym, class... Units>
    struct is_dimensional<Synonym<dimensional_t<Units...>>> : std::true_type {};

    template <class D>
    inline constexpr bool is_dimensional_v = is_dimensional<D>::value;

    // quantity_t traits
    // meta-operator for dimension equivalence
    // primary template
    template <class, class> struct is_same_dimensional : std::false_type {};

    // meta-operator for dimension equivalence
    // template partial specialization for dimensional_t
    template <class T, class U,
              class... Units1,
              class... Units2,
              template <class> class Synonym1,
              template <class> class Synonym2>
    struct is_same_dimensional<quantity_t<Synonym1<dimensional_t<Units1...>>, T>,
                               quantity_t<Synonym2<dimensional_t<Units2...>>, U>>
        : std::conjunction<
            std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
            std::is_base_of<typename Units1::tag,
                            dimensional_t<Units2...>>...> {};

    template <class... Units1,
              class... Units2,
              template <class> class Synonym1,
              template <class> class Synonym2>
    struct is_same_dimensional<Synonym1<dimensional_t<Units1...>>,
                               Synonym2<dimensional_t<Units2...>>>
        : std::conjunction<
            std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
            std::is_base_of<typename Units1::tag,
                            dimensional_t<Units2...>>...> {};

    template <class... Units1,
              class... Units2>
    struct is_same_dimensional<dimensional_t<Units1...>,
                               dimensional_t<Units2...>>
        : std::conjunction<
            std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
            std::is_base_of<typename Units1::tag,
                            dimensional_t<Units2...>>...> {};


    // alias variable template
    template <class L, class R>
    inline constexpr bool is_same_dimensional_v = is_same_dimensional<L, R>::value;

    template < class, class = void >
    struct has_dimensionless_tag_impl: std::false_type {};

    template < class Dim >
    struct has_dimensionless_tag_impl<Dim, typename Dim::dimension_type::is_dimensionless>: std::true_type {};

    template < class Dim >
    struct has_dimensionless_tag: has_dimensionless_tag_impl<Dim> {};

    template < template <class> class, class >
    struct remove_dim_if;

    template < template <class> class Pred, template <class> class Synonym, class T, class... Units >
    struct remove_dim_if<Pred, quantity_t<Synonym<dimensional_t<Units...>>, T>> {
    using type = quantity_t<Synonym<mitamagic::tlist_remove_if_t<Pred, dimensional_t<Units...>>>, T>;
    };

    template < template <class> class Pred, class Q >
    using remove_dim_if_t = typename remove_dim_if<Pred, Q>::type;

    template <class From, class To>
    struct is_dimensional_convertible
        : std::conjunction<
            is_complete_type<converter<From, To>>,
            is_same_dimensional<From, To>>
    {};

    template < class From, class To >
    inline constexpr bool is_dimensional_convertible_v = is_dimensional_convertible<From, To>::value;

    template < class > struct is_dimensional_quantifier: std::false_type {};

    template < template<class>class Synonym, class... Units >
    struct is_dimensional_quantifier<Synonym<dimensional_t<Units...>>>: std::true_type {};

    template <class Q1, class Q2, class... Quantities>
    struct common_quantity
        : ::mitama::common_quantity<
            quantity_t<mitamagic::scaled_dimension_t<typename Q1::dimension_type,
                                                     typename Q2::dimension_type>,
                        std::common_type_t<typename Q1::value_type,
                                           typename Q2::value_type>>,
            Quantities...>
    {
        static_assert(std::conjunction_v<is_same_dimensional<Q1, Q2>,
                                        is_same_dimensional<Q1, Quantities>...>,
                        "dimension type refinement error: "
                        "common_type requires same dimension basis");
    };

    template <class Q1, class Q2> struct common_quantity<Q1, Q2> {
    using type = quantity_t<
        mitamagic::scaled_dimension_t<typename Q1::dimension_type,
                                      typename Q2::dimension_type>,
        std::common_type_t<typename Q1::value_type,
                           typename Q2::value_type>>;
    };

    template <class... Quantities>
    using common_quantity_t = typename common_quantity<Quantities...>::type;

    template <class U, std::intmax_t N>
    using powered_t =
        typename mitamagic::powered_dimensional<U, std::ratio<N>>::type;

    template < class U >
    using reciprocal_t = powered_t<U, -1>;

}

#endif
