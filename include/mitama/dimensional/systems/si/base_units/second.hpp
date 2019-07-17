#ifndef MITAMA_DIMENSIONAL_SI_UNITS_SECOND_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_SECOND_HPP
#include <mitama/dimensional/systems/si/base_units/fwd/si_base_units.hpp>
#include <mitama/dimensional/systems/si/prefix.hpp>
#include <mitama/dimensional/units.hpp>

namespace mitama::systems::si {

using second_t = typename second_base_unit::unit_type_with_system<::mitama::systems::si::system>;

using millisecond_t = scaled_unit_t<second_t, std::milli>;
using microsecond_t = scaled_unit_t<second_t, std::micro>;
using nanosecond_t = scaled_unit_t<second_t, std::nano>;

template < std::intmax_t N = 1 > using second_ = powered_t<second_t, N>;
template < std::intmax_t N = 1 > using millisecond_ = powered_t<millisecond_t, N>;
template < std::intmax_t N = 1 > using microsecond_ = powered_t<microsecond_t, N>;
template < std::intmax_t N = 1 > using nanosecond_ = powered_t<nanosecond_t, N>;


inline constexpr second_t seconds{};
inline constexpr millisecond_t milliseconds{};
inline constexpr microsecond_t microseconds{};
inline constexpr nanosecond_t nanoseconds{};

template < std::intmax_t N = 1 > inline constexpr powered_t<second_t, N> second{};
template < std::intmax_t N = 1 > inline constexpr powered_t<millisecond_t, N> millisecond{};
template < std::intmax_t N = 1 > inline constexpr powered_t<microsecond_t, N> microsecond{};
template < std::intmax_t N = 1 > inline constexpr powered_t<nanosecond_t, N> nanosecond{};


}

#endif
