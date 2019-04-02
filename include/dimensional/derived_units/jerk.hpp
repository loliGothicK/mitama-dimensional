#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_JERK_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_JERK_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using jerk_t = decltype(meters * second<-3>);

inline constexpr jerk_t jerk{};
}

namespace mitama {
template <> struct abbreviation<si::jerk_t> { static constexpr char str[] = "m/s^3"; };
}

#endif
