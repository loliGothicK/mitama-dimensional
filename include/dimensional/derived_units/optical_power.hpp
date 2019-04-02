#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_OPTICAL_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_OPTICAL_POWER_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using optical_power_t = reciprocal_t<meter_t>;

inline constexpr optical_power_t optical_power{};
}

#endif
