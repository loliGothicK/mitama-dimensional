#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_CHARGE_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_CHARGE_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "electric_charge.hpp"

namespace mitama::si {
using linear_charge_density_t = decltype(coulomb / meter<>);

inline constexpr linear_charge_density_t linear_charge_density{};
}

namespace mitama {
template <> struct abbreviation<si::linear_charge_density_t> { static constexpr char str[] = "C/m"; };
}
#endif
