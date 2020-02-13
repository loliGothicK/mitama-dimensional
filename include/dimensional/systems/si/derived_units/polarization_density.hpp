#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POLARIZATION_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POLARIZATION_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "electric_charge.hpp"

namespace mitama::systems::si {
template<class> struct polarization_density_synonym{};
using polarization_density_t = make_synonym_t<polarization_density_synonym, decltype(coulomb / meter<2>)>;

inline constexpr polarization_density_t polarization_density{};

}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_DISPLACEMENT_FIELD_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::polarization_density_t> { static constexpr char str[] = "C/m^2"; };
}
#endif

#endif
