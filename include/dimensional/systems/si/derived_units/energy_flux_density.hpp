#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_FLUX_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_FLUX_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct energy_flux_density_synonym{};
using energy_flux_density_t = make_synonym_t<energy_flux_density_synonym, decltype( joule * meter<-2> * second<-1> )>;

inline constexpr energy_flux_density_t energy_flux_density{};
using energy_flux_density_r = make_refinement_symbol_t<energy_flux_density_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::energy_flux_density_t> { static constexpr char str[] = "J/(m^2 s)"; };
}
#endif
