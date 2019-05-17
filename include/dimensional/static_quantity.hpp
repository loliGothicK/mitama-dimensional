#ifndef MITAMA_DIMENSIONAL_STATIC_QUANTITY_HPP
#define MITAMA_DIMENSIONAL_STATIC_QUANTITY_HPP
#include <dimensional/fwd/quantity_fwd.hpp>
#include <dimensional/mitamagic/quotient.hpp>
#include <dimensional/mitamagic/ratio_ext.hpp>
#include <dimensional/mitamagic/type_traits_ext.hpp>

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
            return (((void)Indices, a) * ... * T{1});
        } 

        template < class T >
        static constexpr auto invoke(T a) { return impl(a, std::make_index_sequence<N>{}); }
    };


    template < class... Units, template <class> class Synonym, auto Value >
    struct static_quantity_t<Synonym<dimensional_t<Units...>>, Value>
    {
        using value_type = decltype(Value);
        static constexpr value_type value = Value;

        constexpr static_quantity_t<Synonym<dimensional_t<Units...>>, -Value>
        operator-() const { return {}; }
    };

    template < class Dim, auto Value >
    inline constexpr static_quantity_t<Dim, Value> static_quantity{};

    template <class D1, class D2, class T, auto V1, auto V2, class F>
    static constexpr auto make_scaled_value() {
        auto [l, r] = mitama::mitamagic::scaler<D1, D2>::template value<T>();
        return F::invoke(V1 * l, V2 * r);
    }

    template < class... Units1, template <class> class Synonym1, auto Value1,
               class... Units2, template <class> class Synonym2, auto Value2,
               std::enable_if_t<
                   is_same_dimensional_v<
                       dimensional_t<Units1...>,
                       dimensional_t<Units2...>>,
               bool> = false >
    inline constexpr auto
    operator+ (static_quantity_t<Synonym1<dimensional_t<Units1...>>, Value1>,
               static_quantity_t<Synonym2<dimensional_t<Units2...>>, Value2>) noexcept
        -> static_quantity_t<mitamagic::scaled_dimension_t<dimensional_t<Units1...>, dimensional_t<Units2...>>,
                             make_scaled_value<dimensional_t<Units1...>,
                                               dimensional_t<Units2...>,
                                               std::common_type_t<decltype(Value1), decltype(Value2)>,
                                               Value1, Value2, Add>()>
        { return {}; }

    template < class... Units1, template <class> class Synonym1, auto Value1,
               class... Units2, template <class> class Synonym2, auto Value2,
                   std::enable_if_t<
                   is_same_dimensional_v<
                       dimensional_t<Units1...>,
                       dimensional_t<Units2...>>,
               bool> = false >
    inline constexpr auto
    operator- (static_quantity_t<Synonym1<dimensional_t<Units1...>>, Value1>,
               static_quantity_t<Synonym2<dimensional_t<Units2...>>, Value2>) noexcept
        -> static_quantity_t<mitamagic::scaled_dimension_t<dimensional_t<Units1...>, dimensional_t<Units2...>>,
                             make_scaled_value<dimensional_t<Units1...>,
                                               dimensional_t<Units2...>,
                                               std::common_type_t<decltype(Value1), decltype(Value2)>,
                                               Value1, Value2, Sub>()>
        { return {}; }

    template < class... Units1, template <class> class Synonym1, auto Value1,
               class... Units2, template <class> class Synonym2, auto Value2 >
    inline constexpr auto
    operator* (static_quantity_t<Synonym1<dimensional_t<Units1...>>, Value1>,
               static_quantity_t<Synonym2<dimensional_t<Units2...>>, Value2>) noexcept
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
    operator/ (static_quantity_t<Synonym1<dimensional_t<Units1...>>, Value1>,
               static_quantity_t<Synonym2<dimensional_t<Units2...>>, Value2>) noexcept
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
    pow(static_quantity_t<Synonym<dimensional_t<Units...>>, Value>) noexcept
        -> static_quantity_t<powered_t<Synonym<dimensional_t<Units...>>, 2>, Pow<N>::invoke(Value)>
        { return {}; }

    template < template < auto > class Pred, class Dim, class T > 
    class refined<Pred, quantity_t<Dim, T>> {
        quantity_t<Dim, T> quantity_;
    public:
        template < auto Value, class Dimension,
            std::enable_if_t<std::conjunction_v<
                std::is_constructible<
                    quantity_t<Dim, T>,
                    quantity_t<Dimension, decltype(Value)>>,
                Pred<Value>>
            , bool> = false>
        constexpr refined(static_quantity_t<Dimension, Value>)
            : quantity_(quantity_t<Dimension, decltype(Value)>(Value))
        {}

        constexpr auto get() const noexcept { return quantity_; }
    };
}

namespace mitama::mitamagic {
    template < std::size_t B, std::size_t E >
	struct Exponent_ : std::integral_constant<std::size_t, B*Exponent_<B,E-1>::value> {};
	
	template < std::size_t B >
	struct Exponent_<B, 1> : std::integral_constant<std::size_t, B> {};
	
	
	template < std::size_t Head, std::size_t... Digits >
	struct to_decimal
		: std::integral_constant<std::size_t, (Head-'0')*Exponent_<10, sizeof...(Digits)>::value + to_decimal<Digits...>::value > {};
	
	template < std::size_t Head >
	struct to_decimal<Head>
		: std::integral_constant<std::size_t, Head-'0'> {};

    template < std::size_t... Digits >
    inline constexpr std::size_t to_decimal_v = to_decimal<Digits...>::value;
}

#include <dimensional/systems/si/all.hpp>

namespace mitama::literals::static_quantity_literals {
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::meter_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _m() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::millimeter_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _mm() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::kilometer_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _km() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::milligram_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _mg() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::gram_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _g() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::kilogram_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _kg() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::nanosecond_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _ns() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::microsecond_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _us() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::millisecond_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _ms() {
    return {};
}
template<char... Chars>
constexpr
static_quantity_t<
    mitama::systems::si::second_t,
    static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
operator"" _s() {
    return {};
}

}

#endif