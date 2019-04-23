#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_CONDUCTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "power.hpp"


namespace mitama::si {
template<class> struct thermal_conductivity_repr{};
using thermal_conductivity_t = make_synonym_t<thermal_conductivity_repr, decltype( watt * meter<-1> * kelvin<-1> )>;

inline constexpr thermal_conductivity_t thermal_conductivity{};
using thermal_conductivity_r = make_refiment_symbol_t<thermal_conductivity_t>;
}

namespace mitama {
template <> struct abbreviation<si::thermal_conductivity_t> { static constexpr char str[] = "W/(m·K)"; };
}
#endif
