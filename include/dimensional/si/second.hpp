#pragma once
#include "../units.hpp"
#include "../quotient.hpp"

namespace mitama {

struct time {
    using is_base_dimension = void;
};

using second_t = make_unit_t<time>;
using millisecond_t = scaled_unit_t<second_t, std::milli>;
using microsecond_t = scaled_unit_t<second_t, std::micro>;
using nanosecond_t = scaled_unit_t<second_t, std::nano>;

inline constexpr second_t seconds{};
inline constexpr millisecond_t milliseconds{};
inline constexpr microsecond_t microseconds{};
inline constexpr nanosecond_t nanoseconds{};

template < std::intmax_t N = 1 > inline constexpr powered_t<second_t, N> second{};
template < std::intmax_t N = 1 > inline constexpr powered_t<millisecond_t, N> millisecond{};
template < std::intmax_t N = 1 > inline constexpr powered_t<microsecond_t, N> microsecond{};
template < std::intmax_t N = 1 > inline constexpr powered_t<nanosecond_t, N> nanosecond{};


}