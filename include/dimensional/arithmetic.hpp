#ifndef MITAMA_DIMENSIONAL_ARITHMETIC_HPP
#define MITAMA_DIMENSIONAL_ARITHMETIC_HPP
#include "quantity.hpp"
#include "delta.hpp"

namespace mitama {

//--------------------------//
//!- Arithmetic Operators -!//
//--------------------------//

template <class L, class R,
          std::enable_if_t<
            std::conjunction_v<
                is_same_dimensional<std::decay_t<L>, std::decay_t<R>>,
                is_addable_with<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>>
        , bool> = false>
constexpr auto
operator+(L &&lhs, R &&rhs)
{
    using result_type = std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>;
    return quantity_t<mitamagic::scaled_dimension_t<typename std::decay_t<L>::dimension_type, typename std::decay_t<R>::dimension_type>, result_type>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a + b; })
        };
}

template <class L, class R,
          std::enable_if_t<
            std::conjunction_v<
                is_same_dimensional<std::decay_t<L>, std::decay_t<R>>,
                is_subtractible_with<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>>
        , bool> = false>
constexpr auto
operator-(L &&lhs, R &&rhs)
{
    using result_type = std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>;
    return quantity_t<mitamagic::scaled_dimension_t<typename std::decay_t<L>::dimension_type, typename std::decay_t<R>::dimension_type>, result_type>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a - b; })
        };
}

template <class L, class R,
          std::enable_if_t<std::conjunction_v<
            is_quantity<std::decay_t<L>>,
            is_quantity<std::decay_t<R>>,
            is_multipliable_with<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>>
        , bool> = false>
constexpr auto
operator*(L &&lhs, R &&rhs)
{
    return quantity_t<
            mitamagic::quotient_t<typename std::decay_t<L>::dimension_type,
                                    typename std::decay_t<R>::dimension_type
            >,
            std::common_type_t<typename std::decay_t<L>::value_type,
                                typename std::decay_t<R>::value_type>>
        {
            mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a * b; })
        };
}

template <class L,
          std::enable_if_t<
            std::conjunction_v<
                is_quantity<std::decay_t<L>>,
                is_multipliable<typename std::decay_t<L>::value_type>>
        , bool> = false>
constexpr auto
operator*(L &&lhs, typename std::decay_t<L>::value_type const& rhs)
{
    return std::decay_t<L>(std::forward<L>(lhs).value() * rhs);
}

template <class R,
          std::enable_if_t<
            std::conjunction_v<
                is_quantity<std::decay_t<R>>,
                is_multipliable<typename std::decay_t<R>::value_type>>
        , bool> = false>
constexpr auto
operator*(typename std::decay_t<R>::value_type const& lhs, R&& rhs)
{
    return std::decay_t<R>(std::forward<R>(rhs).value() * lhs);
}

template <class L, class R,
          std::enable_if_t<std::conjunction_v<
            is_quantity<std::decay_t<L>>,
            is_quantity<std::decay_t<R>>,
            is_dividable_with<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>>
        , bool> = false>
constexpr auto
operator/(L &&lhs, R &&rhs)
{
    return quantity_t<
            mitamagic::quotient_t<typename std::decay_t<L>::dimension_type, mitamagic::inverse_t<typename std::decay_t<R>::dimension_type>>,
            std::common_type_t<typename std::decay_t<L>::value_type, typename std::decay_t<R>::value_type>
        >
        { mitamagic::scaled_value(std::forward<L>(lhs), std::forward<R>(rhs), [](auto a, auto b){ return a / b; }) };
}

template <class L,
          std::enable_if_t<
            std::conjunction_v<
                is_quantity<std::decay_t<L>>,
                is_dividable<typename std::decay_t<L>::value_type>>
        , bool> = false>
constexpr auto
operator/(L &&lhs, typename std::decay_t<L>::value_type const& rhs)
{
    return std::decay_t<L>(std::forward<L>(lhs).value() / rhs);
}

template <class R,
          std::enable_if_t<
            std::conjunction_v<
                is_quantity<std::decay_t<R>>,
                is_dividable<typename std::decay_t<R>::value_type>>
        , bool> = false>
constexpr auto
operator/(typename std::decay_t<R>::value_type const& lhs, R&& rhs)
{
    return quantity_t<
            si_base_units<mitamagic::inverse_t<typename std::decay_t<R>::dimension_type>>,
            typename std::decay_t<R>::value_type
        >
        { lhs / std::forward<R>(rhs).value() };
}


}
#endif