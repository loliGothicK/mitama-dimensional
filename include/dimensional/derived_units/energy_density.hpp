#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "energy.hpp"

namespace mitama::si {
using energy_density_t = decltype(joule / meter<3>);

inline constexpr energy_density_t energy_density{};
}

namespace mitama {
template <> struct abbreviation<si::energy_density_t> { static constexpr char str[] = "J/m^3"; };
}
#endif