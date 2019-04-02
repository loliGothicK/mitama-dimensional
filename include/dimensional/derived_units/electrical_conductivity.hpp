#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRICAL_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRICAL_CONDUCTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "conductance.hpp"

namespace mitama::si {
using electrical_conductivity_t = decltype(siemens / meter<>);

inline constexpr electrical_conductivity_t electrical_conductivity{};
}

namespace mitama {
template <> struct abbreviation<si::electrical_conductivity_t> { static constexpr char str[] = "S/m"; };
}
#endif
