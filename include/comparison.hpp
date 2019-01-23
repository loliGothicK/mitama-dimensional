#ifndef MITAMA_DIMENSIONAL_COMPARISON_HPP
#define MITAMA_DIMENSIONAL_COMPARISON_HPP
#include "quantity.hpp"

namespace mitama {
    template < class Q1, class Q2 >
    constexpr
    std::enable_if_t<::mitama::is_same_dimensional_v<std::decay_t<Q1>, std::decay_t<Q2>>, bool>
    operator < (Q1&& q1, Q2&& q2)
    {
        using common_quantity_t = ::mitama::common_type_t<std::decay_t<Q1>, std::decay_t<Q2>>;
        return static_cast<common_quantity_t>(std::forward<Q1>(q1)).get() < static_cast<common_quantity_t>(std::forward<Q2>(q2)).get();
    }
    template < class Q1, class Q2 >
    constexpr
    std::enable_if_t<::mitama::is_same_dimensional_v<std::decay_t<Q1>, std::decay_t<Q2>>, bool>
    operator > (Q1&& q1, Q2&& q2)
    {
        using common_quantity_t = ::mitama::common_type_t<std::decay_t<Q1>, std::decay_t<Q2>>;
        return static_cast<common_quantity_t>(std::forward<Q1>(q1)).get() > static_cast<common_quantity_t>(std::forward<Q2>(q2)).get();
    }
    template < class Q1, class Q2 >
    constexpr
    std::enable_if_t<::mitama::is_same_dimensional_v<std::decay_t<Q1>, std::decay_t<Q2>>, bool>
    operator <= (Q1&& q1, Q2&& q2)
    {
        using common_quantity_t = ::mitama::common_type_t<std::decay_t<Q1>, std::decay_t<Q2>>;
        return static_cast<common_quantity_t>(std::forward<Q1>(q1)).get() <= static_cast<common_quantity_t>(std::forward<Q2>(q2)).get();
    }
    template < class Q1, class Q2 >
    constexpr
    std::enable_if_t<::mitama::is_same_dimensional_v<std::decay_t<Q1>, std::decay_t<Q2>>, bool>
    operator >= (Q1&& q1, Q2&& q2)
    {
        using common_quantity_t = ::mitama::common_type_t<std::decay_t<Q1>, std::decay_t<Q2>>;
        return static_cast<common_quantity_t>(std::forward<Q1>(q1)).get() >= static_cast<common_quantity_t>(std::forward<Q2>(q2)).get();
    }
    template < class Q1, class Q2 >
    constexpr
    std::enable_if_t<::mitama::is_same_dimensional_v<std::decay_t<Q1>, std::decay_t<Q2>>, bool>
    operator == (Q1&& q1, Q2&& q2)
    {
        using common_quantity_t = ::mitama::common_type_t<std::decay_t<Q1>, std::decay_t<Q2>>;
        return static_cast<common_quantity_t>(std::forward<Q1>(q1)).get() == static_cast<common_quantity_t>(std::forward<Q2>(q2)).get();
    }
    template < class Q1, class Q2 >
    constexpr
    std::enable_if_t<::mitama::is_same_dimensional_v<std::decay_t<Q1>, std::decay_t<Q2>>, bool>
    operator != (Q1&& q1, Q2&& q2)
    {
        using common_quantity_t = ::mitama::common_type_t<std::decay_t<Q1>, std::decay_t<Q2>>;
        return static_cast<common_quantity_t>(std::forward<Q1>(q1)).get() != static_cast<common_quantity_t>(std::forward<Q2>(q2)).get();
    }

}

#endif