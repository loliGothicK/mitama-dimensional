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

    template <class D, class T, class S>
    struct is_quantity<quantity_t<D, T, S>> : std::true_type {};

    template <class D, class T, class S>
    struct is_quantity<const quantity_t<D, T, S>> : std::true_type {};

    template <class D, class T, class S>
    struct is_quantity<volatile quantity_t<D, T, S>> : std::true_type {};

    template <class D, class T, class S>
    struct is_quantity<const volatile quantity_t<D, T, S>> : std::true_type {};

    template <class T> inline constexpr bool is_quantity_v = is_quantity<T>::value;

    template < class, class >
    struct is_same_system;

    template < class D1, class D2, class T1, class T2, class S1, class S2 >
    struct is_same_system<quantity_t<D1, T1, S1>, quantity_t<D2, T2, S2>>
      : std::disjunction<
          std::is_same<S1, system<>>,
          std::is_same<S2, system<>>,
          std::is_same<S1, S2>
        >
    {};

    template < class Q, class R >
    inline constexpr bool is_same_system_v = is_same_system<Q, R>::value;

    // units_t traits
    template <class> struct is_units : std::false_type {};

    template <int I, class D, class E, class S, class Sys>
    struct is_units<units_t<I, D, E, S, Sys>> : std::true_type {};

    template <int I, class D, class E, class S, class Sys>
    struct is_units<const units_t<I, D, E, S, Sys>> : std::true_type {};

    template <int I, class D, class E, class S, class Sys>
    struct is_units<volatile units_t<I, D, E, S, Sys>> : std::true_type {};

    template <int I, class D, class E, class S, class Sys>
    struct is_units<const volatile units_t<I, D, E, S, Sys>> : std::true_type {};

    template <class U> inline constexpr bool is_units_v = is_units<U>::value;

    // dimensional_t traits
    template <class> struct is_dimensional : std::false_type {};

    template <template <class> class Synonym, class... Units>
    struct is_dimensional<Synonym<dimensional_t<Units...>>> : std::true_type {};

    template <template <class> class Synonym, class... Units>
    struct is_dimensional<const Synonym<dimensional_t<Units...>>> : std::true_type {};

    template <template <class> class Synonym, class... Units>
    struct is_dimensional<volatile Synonym<dimensional_t<Units...>>> : std::true_type {};

    template <template <class> class Synonym, class... Units>
    struct is_dimensional<const volatile Synonym<dimensional_t<Units...>>> : std::true_type {};

    template <class D>
    inline constexpr bool is_dimensional_v = is_dimensional<D>::value;

namespace mitamagic {
    template < class, class > struct is_same_dimensional_impl: std::false_type {};

    template <class T, class U,
              class... Units1,
              class... Units2,
              template <class> class Synonym1,
              template <class> class Synonym2,
              class... S>
    struct is_same_dimensional_impl<quantity_t<Synonym1<dimensional_t<Units1...>>, T, system<S...>>,
                                    quantity_t<Synonym2<dimensional_t<Units2...>>, U, system<S...>>>
        : std::conjunction<
            mitama::is_same_system<quantity_t<Synonym1<dimensional_t<Units1...>>, T, system<S...>>,
                                   quantity_t<Synonym2<dimensional_t<Units2...>>, U, system<S...>>>,
            std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
            std::is_base_of<typename Units1::tag,
                            dimensional_t<Units2...>>...> {};

    template <class... Units1,
              class... Units2,
              template <class> class Synonym1,
              template <class> class Synonym2>
    struct is_same_dimensional_impl<Synonym1<dimensional_t<Units1...>>,
                                    Synonym2<dimensional_t<Units2...>>>
        : std::conjunction<
            std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
            std::is_base_of<typename Units1::tag,
                            dimensional_t<Units2...>>...> {};

    template <class... Units1,
              class... Units2>
    struct is_same_dimensional_impl<dimensional_t<Units1...>,
                                    dimensional_t<Units2...>>
        : std::conjunction<
            std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
            std::is_base_of<typename Units1::tag,
                            dimensional_t<Units2...>>...> {};
}

    template <class T, class U> using is_same_dimensional = mitamagic::is_same_dimensional_impl<std::decay_t<T>, std::decay_t<U>>;

    // alias variable template
    template <class L, class R>
    inline constexpr bool is_same_dimensional_v = is_same_dimensional<L, R>::value;

namespace mitamagic {
    template < class, class = void >
    struct has_dimensionless_tag_impl: std::false_type {};

    template < class Dim >
    struct has_dimensionless_tag_impl<Dim, typename std::decay_t<Dim>::dimension_type::is_dimensionless>: std::true_type {};
}
    template < class Dim >
    struct has_dimensionless_tag: mitamagic::has_dimensionless_tag_impl<Dim> {};

    template < template <class> class, class >
    struct remove_dim_if;

    template < template <class> class Pred, template <class> class Synonym, class T, class... Units, class... Dim >
    struct remove_dim_if<Pred, quantity_t<Synonym<dimensional_t<Units...>>, T, system<Dim...>>> {
        using type = quantity_t<Synonym<mitamagic::tlist_remove_if_t<Pred, dimensional_t<Units...>>>, T, system<Dim...>>;
    };
    template < template <class> class Pred, template <class> class Synonym, class T, class... Units, class... Dim >
    struct remove_dim_if<Pred, const quantity_t<Synonym<dimensional_t<Units...>>, T, system<Dim...>>> {
        using type = const quantity_t<Synonym<mitamagic::tlist_remove_if_t<Pred, dimensional_t<Units...>>>, T, system<Dim...>>;
    };
    template < template <class> class Pred, template <class> class Synonym, class T, class... Units, class... Dim >
    struct remove_dim_if<Pred, volatile quantity_t<Synonym<dimensional_t<Units...>>, T, system<Dim...>>> {
        using type = volatile quantity_t<Synonym<mitamagic::tlist_remove_if_t<Pred, dimensional_t<Units...>>>, T, system<Dim...>>;
    };
    template < template <class> class Pred, template <class> class Synonym, class T, class... Units, class... Dim >
    struct remove_dim_if<Pred, const volatile quantity_t<Synonym<dimensional_t<Units...>>, T, system<Dim...>>> {
        using type = const volatile quantity_t<Synonym<mitamagic::tlist_remove_if_t<Pred, dimensional_t<Units...>>>, T, system<Dim...>>;
    };

    template < template <class> class Pred, class Q >
    using remove_dim_if_t = typename remove_dim_if<Pred, Q>::type;

    template <class From, class To>
    struct is_dimensional_convertible
        : std::conjunction<
            is_complete_type<converter<std::decay_t<From>, std::decay_t<To>>>,
            is_same_dimensional<std::decay_t<From>, std::decay_t<To>>>
    {};

    template < class From, class To >
    inline constexpr bool is_dimensional_convertible_v = is_dimensional_convertible<From, To>::value;

    template < class > struct is_dimensional_quantifier: std::false_type {};

    template < template<class>class Synonym, class... Units >
    struct is_dimensional_quantifier<Synonym<dimensional_t<Units...>>>: std::true_type {};
    template < template<class>class Synonym, class... Units >
    struct is_dimensional_quantifier<const Synonym<dimensional_t<Units...>>>: std::true_type {};
    template < template<class>class Synonym, class... Units >
    struct is_dimensional_quantifier<volatile Synonym<dimensional_t<Units...>>>: std::true_type {};
    template < template<class>class Synonym, class... Units >
    struct is_dimensional_quantifier<const volatile Synonym<dimensional_t<Units...>>>: std::true_type {};

    template < class T >
    inline constexpr bool is_dimensional_quantifier_v = is_dimensional_quantifier<T>::value;

    template <class Q1, class Q2, class... Quantities>
    struct common_quantity
        : ::mitama::common_quantity<
            quantity_t<mitamagic::scaled_dimension_t<typename std::decay_t<Q1>::dimension_type,
                                                     typename std::decay_t<Q2>::dimension_type>,
                        std::common_type_t<typename std::decay_t<Q1>::value_type,
                                           typename std::decay_t<Q2>::value_type>>,
            Quantities...>
    {
        static_assert(std::conjunction_v<is_same_dimensional<Q1, Q2>,
                                         is_same_dimensional<Q1, Quantities>...>,
                        "dimension type refinement error: "
                        "common_type requires same dimension basis");
    };

    template <class Q1, class Q2> struct common_quantity<Q1, Q2> {
    using type = quantity_t<
        mitamagic::scaled_dimension_t<typename std::decay_t<Q1>::dimension_type,
                                      typename std::decay_t<Q2>::dimension_type>,
        std::common_type_t<typename std::decay_t<Q1>::value_type,
                           typename std::decay_t<Q2>::value_type>>;
    };

    template <class... Quantities>
    using common_quantity_t = typename common_quantity<Quantities...>::type;

    template <class U, std::intmax_t N>
    using powered_t =
        typename mitamagic::powered_dimensional<std::decay_t<U>, std::ratio<N>>::type;

    template < class U >
    using reciprocal_t = powered_t<U, -1>;
}

#endif
