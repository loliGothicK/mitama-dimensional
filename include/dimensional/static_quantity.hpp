#ifndef MITAMA_DIMENSIONAL_STATIC_QUANTITY_HPP
#define MITAMA_DIMENSIONAL_STATIC_QUANTITY_HPP
#include "fwd/quantity_fwd.hpp"
#include "mitamagic/quotient.hpp"
#include "mitamagic/ratio_ext.hpp"
#include "mitamagic/type_traits_ext.hpp"

namespace mitama {

    struct Add {
        template < class T >
        static constexpr auto invoke(T a, T b) { return a + b; }
    };
    struct Sub {
        template < class T >
        static constexpr auto invoke(T a, T b) { return a - b; }
    };
    struct Mul {
        template < class T >
        static constexpr auto invoke(T a, T b) { return a * b; }
    };
    struct Div {
        template < class T >
        static constexpr auto invoke(T a, T b) { return a / b; }
    };
    template < std::size_t N >
    struct Pow {
        template < class T, std::size_t... Indices >
        static constexpr auto impl(T a,std::index_sequence<Indices...>) {
            return ((Indices, a) * ... * T{1});
        } 

        template < class T >
        static constexpr auto invoke(T a) { return impl(a, std::make_index_sequence<N>{}); }
    };


    template < class, auto >
    struct static_quantity_t;

    template < class... Units, template <class> class Synonym, auto Value >
    struct static_quantity_t<Synonym<dimensional_t<Units...>>, Value>
    {
        using value_type = decltype(Value);
        static constexpr value_type value = Value;
    };

    template < class Dim, auto Value >
    inline constexpr static_quantity_t<Dim, Value> static_quantity{};

    template <class D1, class D2, class T, auto V1, auto V2, class F>
    static constexpr auto make_scaled_value() {
        auto [l, r] = mitama::mitamagic::scaler<D1, D2>::template value<T>();
        return F::invoke(V1 * l, V2 * r);
    }

    template < class... Units1, template <class> class Synonym1, auto Value1,
               class... Units2, template <class> class Synonym2, auto Value2 >
    inline constexpr auto
    operator+ (static_quantity_t<Synonym1<dimensional_t<Units1...>>, Value1>, static_quantity_t<Synonym2<dimensional_t<Units2...>>, Value2>)
        -> static_quantity_t<mitamagic::scaled_dimension_t<dimensional_t<Units1...>, dimensional_t<Units2...>>,
                             make_scaled_value<dimensional_t<Units1...>,
                                               dimensional_t<Units2...>,
                                               std::common_type_t<decltype(Value1), decltype(Value2)>,
                                               Value1, Value2, Add>()>
        { return {}; }

    template < class... Units1, template <class> class Synonym1, auto Value1,
               class... Units2, template <class> class Synonym2, auto Value2 >
    inline constexpr auto
    operator- (static_quantity_t<Synonym1<dimensional_t<Units1...>>, Value1>, static_quantity_t<Synonym2<dimensional_t<Units2...>>, Value2>)
        -> static_quantity_t<mitamagic::scaled_dimension_t<dimensional_t<Units1...>, dimensional_t<Units2...>>,
                             make_scaled_value<dimensional_t<Units1...>,
                                               dimensional_t<Units2...>,
                                               std::common_type_t<decltype(Value1), decltype(Value2)>,
                                               Value1, Value2, Sub>()>
        { return {}; }

    template < class... Units1, template <class> class Synonym1, auto Value1,
               class... Units2, template <class> class Synonym2, auto Value2 >
    inline constexpr auto
    operator* (static_quantity_t<Synonym1<dimensional_t<Units1...>>, Value1>, static_quantity_t<Synonym2<dimensional_t<Units2...>>, Value2>)
        -> static_quantity_t<mitamagic::quotient_t<dimensional_t<Units1...>,
                                                   dimensional_t<Units2...>>,
                             make_scaled_value<dimensional_t<Units1...>,
                                               dimensional_t<Units2...>,
                                               std::common_type_t<decltype(Value1), decltype(Value2)>,
                                               Value1, Value2, Mul>()>
        { return {}; }

    template < class... Units1, template <class> class Synonym1, auto Value1,
               class... Units2, template <class> class Synonym2, auto Value2 >
    inline constexpr auto
    operator/ (static_quantity_t<Synonym1<dimensional_t<Units1...>>, Value1>, static_quantity_t<Synonym2<dimensional_t<Units2...>>, Value2>)
        -> static_quantity_t<mitamagic::quotient_t<dimensional_t<Units1...>,
                                                   mitamagic::inverse_t<dimensional_t<Units2...>>>,
                             make_scaled_value<dimensional_t<Units1...>,
                                               dimensional_t<Units2...>,
                                               std::common_type_t<decltype(Value1), decltype(Value2)>,
                                               Value1, Value2, Div>()>
        { return {}; }

    template < std::size_t N,
               class... Units, template <class> class Synonym, auto Value >
    inline constexpr auto
    pow(static_quantity_t<Synonym<dimensional_t<Units...>>, Value>)
        -> static_quantity_t<powered_t<Synonym<dimensional_t<Units...>>, 2>, Pow<N>::invoke(Value)>
        { return {}; }

}

#endif