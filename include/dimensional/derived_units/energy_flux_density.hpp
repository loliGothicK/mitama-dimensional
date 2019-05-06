#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_FLUX_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_FLUX_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "energy.hpp"

namespace mitama::si {
template<class> struct energy_flux_density_repr{};
using energy_flux_density_t = make_synonym_t<energy_flux_density_repr, decltype( joule * meter<-2> * second<-1> )>;

inline constexpr energy_flux_density_t energy_flux_density{};
using energy_flux_density_r = make_refinement_symbol_t<energy_flux_density_t>;
}

namespace mitama {
template <> struct abbreviation<si::energy_flux_density_t> { static constexpr char str[] = "J/(m^2·s)"; };
}
#endif
