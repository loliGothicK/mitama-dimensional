#ifndef MITAMA_DIMENSIONAL_DIMENSIONAL_TRAITS_HPP
#define MITAMA_DIMENSIONAL_DIMENSIONAL_TRAITS_HPP
#include "fwd/quantity_fwd.hpp"
#include "fwd/units_fwd.hpp"
#include "fwd/dimensional_fwd.hpp"
#include "mitamagic/type_traits_ext.hpp"
#include "mitamagic/type_list.hpp"
#include <type_traits>
#include "mitamagic/quotient.hpp"

namespace mitama {
    // units_t traits
    template <class> struct is_units : std::false_type {};

    template <class D, class E, class S>
    struct is_units<units_t<D, E, S>> : std::true_type {};

    template <class U> inline constexpr bool is_units_v = is_units<U>::value;

    // dimensional_t traits
    template <class> struct is_dimensional : std::false_type {};

    template <template <class> class Repr, class... Units>
    struct is_dimensional<Repr<dimensional_t<Units...>>> : std::true_type {};

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
            template <class> class Repr1,
            template <class> class Repr2>
    struct is_same_dimensional<quantity_t<Repr1<dimensional_t<Units1...>>, T>,
                            quantity_t<Repr2<dimensional_t<Units2...>>, U>>
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

    template < template <class> class Pred, template <class> class Repr, class T, class... Units >
    struct remove_dim_if<Pred, quantity_t<Repr<dimensional_t<Units...>>, T>> {
    using type = quantity_t<Repr<mitamagic::tlist_remove_if_t<Pred, dimensional_t<Units...>>>, T>;
    };

    template < template <class> class Pred, class Q >
    using remove_dim_if_t = typename remove_dim_if<Pred, Q>::type;

    template <class From, class To>
    struct is_dimensional_convertible
        : std::conjunction<
            is_complete_type<converter<From, To>>,
            is_same_dimensional<From, To>>
    {};

    template < class > struct is_dimensional_quantifier: std::false_type {};

    template < template<class>class Repr, class... Units >
    struct is_dimensional_quantifier<Repr<dimensional_t<Units...>>>: std::true_type {};

    template <class Q1, class Q2, class... Quantities>
    struct common_type
        : ::mitama::common_type<
            quantity_t<mitamagic::scaled_demension_t<typename Q1::dimension_type,
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

    template <class... Quantities>
    using common_type_t = typename common_type<Quantities...>::type;

    template <class Q1, class Q2> struct common_type<Q1, Q2> {
    using type = quantity_t<
        mitamagic::scaled_demension_t<typename Q1::dimension_type,
                                        typename Q2::dimension_type>,
        std::common_type_t<typename Q1::value_type, typename Q2::value_type>>;
    };

    template <class U, std::intmax_t N>
    using powered_t =
        typename mitamagic::powered_dimensional<U, std::ratio<N>>::type;

    template < class U >
    using reciprocal_t = powered_t<U, -1>;

}

#endif
