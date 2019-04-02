#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENERGY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "energy.hpp"

namespace mitama::si {
using specific_energy_t = decltype(joule / kilogram<>);

inline constexpr specific_energy_t specific_energy{};
}

namespace mitama {
template <> struct abbreviation<si::specific_energy_t> { static constexpr char str[] = "J/kg"; };
}
#endif
