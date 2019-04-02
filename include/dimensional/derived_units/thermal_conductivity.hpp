#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_CONDUCTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"


namespace mitama::si {
using thermal_conductivity_t = decltype( watt * meter<-1> * kelvin<-1> );

inline constexpr thermal_conductivity_t thermal_conductivity{};
}

namespace mitama {
template <> struct abbreviation<si::thermal_conductivity_t> { static constexpr char str[] = "W/(m·K)"; };
}
#endif
