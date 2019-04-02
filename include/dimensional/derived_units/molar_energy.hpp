#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENERGY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "energy.hpp"

namespace mitama::si {
using molar_energy_t = decltype(joule / mol<>);

inline constexpr molar_energy_t molar_energy{};
}

namespace mitama {
template <> struct abbreviation<si::molar_energy_t> { static constexpr char str[] = "J/mol"; };
}
#endif
