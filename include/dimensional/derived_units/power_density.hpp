#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"

namespace mitama::si {
using power_density_t = decltype(watt / meter<3>);

inline constexpr power_density_t power_density{};
}

namespace mitama {
template <> struct abbreviation<si::power_density_t> { static constexpr char str[] = "W/m^3"; };
}
#endif