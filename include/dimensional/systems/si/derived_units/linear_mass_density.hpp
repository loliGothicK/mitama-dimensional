#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_MASS_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_MASS_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct linear_mass_density_synonym{};
using linear_mass_density_t = make_synonym_t<linear_mass_density_synonym, decltype(meter<-1> * kilogram<>)>;

inline constexpr linear_mass_density_t linear_mass_density{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::linear_mass_density_t> { static constexpr char str[] = "kg/m"; };
}

#endif
