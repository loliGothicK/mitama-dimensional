#ifndef MITAMA_DIMENSIONAL_MATH_MINMAX_HPP
#define MITAMA_DIMENSIONAL_MATH_MINMAX_HPP

#include <mitama/dimensional/quantity.hpp>
#include <cmath>

namespace mitama {

template <class First, class Second, class... Quantities
        , std::enable_if_t<std::conjunction_v<is_quantity<std::decay_t<First>>, is_quantity<std::decay_t<Second>>, is_quantity<std::decay_t<Quantities>>...>, bool> = false>
auto min(First first, Second second, Quantities... quantities)
  -> ::mitama::common_quantity_t<First, Second, Quantities...>
{
  using ret = ::mitama::common_quantity_t<First, Second, Quantities...>;
  if constexpr (sizeof...(Quantities) == 0) {
    return first < second ? static_cast<ret>(first) : static_cast<ret>(second);
  } else {
    return ::mitama::min(first < second ? static_cast<ret>(first)
                                        : static_cast<ret>(second),
                         quantities...);
  }
}

template <class First, class Second, class... Quantities
        , std::enable_if_t<std::conjunction_v<is_quantity<std::decay_t<First>>, is_quantity<std::decay_t<Second>>, is_quantity<std::decay_t<Quantities>>...>, bool> = false>
auto max(First first, Second second, Quantities... quantities)
  -> ::mitama::common_quantity_t<First, Second, Quantities...>
{
  using ret = ::mitama::common_quantity_t<First, Second, Quantities...>;
  if constexpr (sizeof...(Quantities) == 0) {
    return first > second ? static_cast<ret>(first) : static_cast<ret>(second);
  } else {
    return ::mitama::max(first > second ? static_cast<ret>(first)
                                        : static_cast<ret>(second),
                         quantities...);
  }
}

template < class Q1, class Q2,
           std::enable_if_t<
             std::is_arithmetic_v<
               typename ::mitama::common_quantity_t<Q1, Q2>::value_type>,
           bool> = false>
auto fdim(Q1&& q1, Q2&& q2) -> ::mitama::common_quantity_t<Q1, Q2>
{
  using std::fdim;
  return ::mitama::common_quantity_t<Q1, Q2>( std::fdim(std::forward<Q1>(q1).value(), std::forward<Q2>(q2).value()) );
}

} // namespace mitama

#endif
