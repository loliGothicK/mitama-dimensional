#pragma once
#include <type_traits>
#include <ratio>
#include <utility>
#include <cmath>
#include "dimensional_phantom.hpp"
#include "dimensional_traits.hpp"

namespace mitama::mitamagic {
    template < class , class > struct prod;
    
    template < class D, class Exp1, class Exp2, class S1, class S2 >
    struct prod<units_t<D, Exp1, S1>, units_t<D, Exp2, S2>>
    {
        using type = type_list<Exp1, S1, Exp2, S2>;
    };
    template < class, class > struct scaler;

    template < class U, class Head, class... Tail >
    struct find_if: std::conditional_t<
        std::is_same_v<typename U::tag, typename Head::tag>,
        prod<U, Head>,
        find_if<U, Tail...>
    >
    {};

    template < class U, class H >
    struct find_if<U, H> {
        using type = std::conditional_t<
            std::is_same_v<typename U::tag, typename H::tag>,
            typename prod<U, H>::type,
            type_list<>>;
    };

    template < class... U1, class... U2 >
    struct scaler<dimensional_t<U1...>, dimensional_t<U2...>> {
        template <class R1, class R2>
        static long double convert(){
            return std::pow(
                    static_cast<long double>(R1::num) / static_cast<long double>(R1::den),
                    static_cast<long double>(R2::num) / static_cast<long double>(R2::den));
        }

        template < class T, class... Seq >
        static constexpr auto eval() {
            auto c = ((convert<tlist_element_t<1,Seq>, tlist_element_t<0,Seq>>() / convert<tlist_element_t<3,Seq>, tlist_element_t<2,Seq>>()) * ... * 1.0l);
            return c < 1.0l ? std::tuple{false, static_cast<T>(1.0l/c)} : std::tuple{true, static_cast<T>(c)};
        }
        template < class T >
        static constexpr auto value() {
            return eval<T, typename find_if<U1, U2...>::type...>();
        }
    };

    template <class Q1, class Q2, class F>
    constexpr auto scaled_value(Q1&& q1, Q2&& q2, F&& f){
        using lhs_t = std::decay_t<Q1>;
        using rhs_t = std::decay_t<Q2>;
        using common_t = std::common_type_t<typename lhs_t::value_type, typename rhs_t::value_type>;
        if (auto [flag, c] = scaler<typename lhs_t::dimension_type, typename rhs_t::dimension_type>::template value<common_t>(); flag)
        {
            return std::forward<F>(f)(std::forward<Q1>(q1).get() * c, std::forward<Q2>(q2).get());
        }
        else
        {
            return std::forward<F>(f)(std::forward<Q1>(q1).get(), std::forward<Q2>(q2).get() * c);
        }
    }

    template < class, class, class >
    struct scaled_demension;

    template < class... L, class... R, std::size_t... I>
    struct scaled_demension<dimensional_t<L...>, dimensional_t<R...>, std::index_sequence<I...>>{
        using type = dimensional_t<
            units_t<
                typename tlist_element_t<I, type_list<L...>>::dimension_type,
                typename tlist_element_t<I, type_list<L...>>::exponent,
                ratio_min<typename tlist_element_t<I, type_list<L...>>::scale, typename tlist_element_t<I, type_list<R...>>::scale>
            >...
        >;
    };

    template < class L, class R >
    using scaled_demension_t = typename scaled_demension<L, R, std::make_index_sequence<L::value>>::type;
}


namespace mitama {

//--------------------------//
//!- Arithmetic Operators -!//
//--------------------------//

template < class L, class R, std::enable_if_t<is_same_dimensional_v<std::decay_t<L>, std::decay_t<R>>, bool> = false>
constexpr auto
operator+(L&& lhs, R&& rhs) {
    using result_type = std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>;
    return quantity_t<mitamagic::scaled_demension_t<typename std::decay_t<L>::dimension_type, typename std::decay_t<R>::dimension_type>, result_type>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a + b; })
        };
}

template < class L, class R, std::enable_if_t<is_same_dimensional_v<std::decay_t<L>, std::decay_t<R>>, bool> = false>
constexpr auto
operator-(L&& lhs, R&& rhs) {
    using result_type = std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>;
    return quantity_t<mitamagic::scaled_demension_t<typename std::decay_t<L>::dimension_type, typename std::decay_t<R>::dimension_type>, result_type>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a - b; })
        };
}

template < class L, class R >
constexpr auto
operator*(L&& lhs, R&& rhs) {
    return quantity_t<quotient_t<typename std::decay_t<L>::dimension_type, typename std::decay_t<R>::dimension_type>, std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a * b; })
        };
}

template < class L, class R >
constexpr auto
operator/(L&& lhs, R&& rhs) {
    return quantity_t<quotient_t<typename std::decay_t<L>::dimension_type, inverse_t<typename std::decay_t<R>::dimension_type>>, std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a / b; })
        };
}
}