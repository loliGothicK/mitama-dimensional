#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_MASS_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_MASS_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct linear_mass_density_repr{};
using linear_mass_density_t = make_synonym_t<linear_mass_density_repr, decltype(meter<-1> * kilogram<>)>;

inline constexpr linear_mass_density_t linear_mass_density{};
using linear_mass_density_r = make_refiment_symbol_t<linear_mass_density_t>;
}

namespace mitama {
template <> struct abbreviation<si::linear_mass_density_t> { static constexpr char str[] = "kg/m"; };
}

#endif
