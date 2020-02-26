#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_DENSITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "power.hpp"

namespace mitama::systems::si {
template<class> struct power_density_synonym{};
using power_density_t = make_synonym_t<power_density_synonym, decltype(watt / meter<3>)>;

inline constexpr power_density_t power_density{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::power_density_t> { static constexpr char str[] = "W/m^3"; };
}
#endif
