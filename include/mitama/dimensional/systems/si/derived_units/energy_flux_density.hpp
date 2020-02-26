#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_FLUX_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_FLUX_DENSITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct energy_flux_density_synonym{};
using energy_flux_density_t = make_synonym_t<energy_flux_density_synonym, decltype( joule * meter<-2> * second<-1> )>;

inline constexpr energy_flux_density_t energy_flux_density{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::energy_flux_density_t> { static constexpr char str[] = "J/(m^2 s)"; };
}
#endif
