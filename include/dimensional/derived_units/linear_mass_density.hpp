#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_MASS_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_MASS_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using linear_mass_density_t = decltype(meter<-1> * kilogram<>);

inline constexpr linear_mass_density_t linear_mass_density{};
}

namespace mitama {
template <> struct abbreviation<si::linear_mass_density_t> { static constexpr char str[] = "kg/m"; };
}

#endif
