#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_DENSITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct energy_density_synonym{};
using energy_density_t = make_synonym_t<energy_density_synonym, decltype(joule / meter<3>)>;

inline constexpr energy_density_t energy_density{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::energy_density_t> { static constexpr char str[] = "J/m^3"; };
}
#endif
