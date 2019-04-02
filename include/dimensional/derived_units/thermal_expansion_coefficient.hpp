#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_EXPANSION_COEFFICIENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_EXPANSION_COEFFICIENT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using thermal_expansion_coefficient_t = reciprocal_t<kelvin_t>;

inline constexpr thermal_expansion_coefficient_t thermal_expansion_coefficient{};
}

#endif
