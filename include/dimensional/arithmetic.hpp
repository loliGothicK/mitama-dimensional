#ifndef MITAMA_DIMENSIONAL_ARITHMETIC_HPP
#define MITAMA_DIMENSIONAL_ARITHMETIC_HPP
#include "quantity.hpp"
#include "expr.hpp"
#include "delta.hpp"

namespace mitama {

//--------------------------//
//!- Arithmetic Operators -!//
//--------------------------//

template <class L, class R,
          std::enable_if_t<is_same_dimensional_v<std::decay_t<L>, std::decay_t<R>>, bool> = false>
constexpr auto
operator+(L &&lhs, R &&rhs)
{
    using result_type = std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>;
    return quantity_t<mitamagic::scaled_demension_t<typename std::decay_t<L>::dimension_type, typename std::decay_t<R>::dimension_type>, result_type>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a + b; })
        };
}

template <class L, class R,
          std::enable_if_t<is_same_dimensional_v<std::decay_t<L>, std::decay_t<R>>, bool> = false>
constexpr auto
operator-(L &&lhs, R &&rhs)
{
    using result_type = std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>;
    return quantity_t<mitamagic::scaled_demension_t<typename std::decay_t<L>::dimension_type, typename std::decay_t<R>::dimension_type>, result_type>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a - b; })
        };
}

template <class L, class R,
          std::enable_if_t<
            std::disjunction_v<is_quantity<std::decay_t<L>>, is_quantity<std::decay_t<R>>> &&
            !is_expr_v<std::decay_t<L>> && !is_expr_v<std::decay_t<R>> &&
            !is_delta_v<std::decay_t<L>> && !is_delta_v<std::decay_t<R>>
            , bool> = false>
constexpr auto
operator*(L &&lhs, R &&rhs)
{
    if constexpr (is_quantity_v<std::decay_t<L>> && is_quantity_v<std::decay_t<R>>) {
        return quantity_t<mitamagic::quotient_t<typename std::decay_t<L>::dimension_type, typename std::decay_t<R>::dimension_type>, std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>>
            {
                mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a * b; })
            };
    }
    else if constexpr (is_quantity_v<std::decay_t<L>>) {
        return std::decay_t<L>(lhs.get() * rhs);
    }
    else {
        return std::decay_t<L>(rhs.get() * lhs);
    }
}

template <class L, class R,
          std::enable_if_t<
            std::disjunction_v<is_quantity<std::decay_t<L>>, is_quantity<std::decay_t<R>>> &&
            !is_expr_v<std::decay_t<L>> && !is_expr_v<std::decay_t<R>> &&
            !is_delta_v<std::decay_t<L>> && !is_delta_v<std::decay_t<R>>
            , bool> = false>
constexpr auto
operator/(L &&lhs, R &&rhs)
{
    if constexpr (is_quantity_v<std::decay_t<L>> && is_quantity_v<std::decay_t<R>>) {
        return quantity_t<
                mitamagic::quotient_t<typename std::decay_t<L>::dimension_type, mitamagic::inverse_t<typename std::decay_t<R>::dimension_type>>,
                std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>
            >{
                mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a / b; })
            };
    }
    else if constexpr (is_quantity_v<std::decay_t<R>>) {
        return quantity<
                mitamagic::inverse_t<typename std::decay_t<R>::dimension_type>, // dimension type
                std::common_type_t<typename std::decay_t<R>::value_type, std::decay_t<L>> // common value_type
            >{
                lhs / rhs.get()
            };
    }
    else {
        return std::decay_t<L>(lhs.get() / rhs);
    }
}

}
#endif