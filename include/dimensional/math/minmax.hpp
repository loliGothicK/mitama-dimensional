#ifndef MITAMA_DIMENSIONAL_MATH_MINMAX_HPP
#define MITAMA_DIMENSIONAL_MATH_MINMAX_HPP

#include "../quantity.hpp"
#include <cmath>

namespace mitama {

template <class First, class Second, class... Quantities>
auto min(First first, Second second, Quantities... quantities)
  -> ::mitama::common_type_t<First, Second, Quantities...>
{
  using ret = ::mitama::common_type_t<First, Second, Quantities...>;
  if constexpr (sizeof...(Quantities) == 0) {
    return first < second ? static_cast<ret>(first) : static_cast<ret>(second);
  } else {
    return ::mitama::min(first < second ? static_cast<ret>(first)
                                        : static_cast<ret>(second),
                         quantities...);
  }
}

template <class First, class Second, class... Quantities>
auto max(First first, Second second, Quantities... quantities)
  -> ::mitama::common_type_t<First, Second, Quantities...>
{
  using ret = ::mitama::common_type_t<First, Second, Quantities...>;
  if constexpr (sizeof...(Quantities) == 0) {
    return first > second ? static_cast<ret>(first) : static_cast<ret>(second);
  } else {
    return ::mitama::max(first > second ? static_cast<ret>(first)
                                        : static_cast<ret>(second),
                         quantities...);
  }
}

template < class Q1, class Q2 >
auto dim(Q1&& q1, Q2&& q2) -> ::mitama::common_type_t<Q1, Q2>
{
  return ::mitama::common_type_t<Q1, Q2>( std::fdim(std::forward<Q1>(q1).get(), std::forward<Q2>(q2).get()) );
}

} // namespace mitama

#endif