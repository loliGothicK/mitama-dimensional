#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_DENSITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>
#include "power.hpp"

namespace mitama::systems::si {
template<class> struct heat_flux_density_synonym{};
using heat_flux_density_t = make_synonym_t<heat_flux_density_synonym, decltype(watt / meter<2>)>;

inline constexpr heat_flux_density_t heat_flux_density{};
using heat_flux_density_r = make_refinement_symbol_t<heat_flux_density_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IRRADIANCE_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::heat_flux_density_t> { static constexpr char str[] = "W/m^2"; };
}
#endif


#endif
