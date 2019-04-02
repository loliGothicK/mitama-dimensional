#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_CONDUCTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "conductance.hpp"

namespace mitama::si {
using molar_conductivity_t = decltype(siemens * meter<2> / mol<>);

inline constexpr molar_conductivity_t molar_conductivity{};
}

namespace mitama {
template <> struct abbreviation<si::molar_conductivity_t> { static constexpr char str[] = "S·m^2/mol"; };
}
#endif
