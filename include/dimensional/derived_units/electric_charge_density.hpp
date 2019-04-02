#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "electric_charge.hpp"

namespace mitama::si {
using electric_charge_density_t = decltype(coulomb / meter<3>);

inline constexpr electric_charge_density_t electric_charge_density{};
inline constexpr electric_charge_density_t charge_density{};
}

namespace mitama {
template <> struct abbreviation<si::electric_charge_density_t> { static constexpr char str[] = "C/m^3"; };
}
#endif
