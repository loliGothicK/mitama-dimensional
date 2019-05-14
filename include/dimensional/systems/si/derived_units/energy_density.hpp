#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct energy_density_synonym{};
using energy_density_t = make_synonym_t<energy_density_synonym, decltype(joule / meter<3>)>;

inline constexpr energy_density_t energy_density{};
using energy_density_r = make_refinement_symbol_t<energy_density_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::energy_density_t> { static constexpr char str[] = "J/m^3"; };
}
#endif
