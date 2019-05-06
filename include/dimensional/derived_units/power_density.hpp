#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "power.hpp"

namespace mitama::si {
template<class> struct power_density_repr{};
using power_density_t = make_synonym_t<power_density_repr, decltype(watt / meter<3>)>;

inline constexpr power_density_t power_density{};
using power_density_r = make_refinement_symbol_t<power_density_t>;
}

namespace mitama {
template <> struct abbreviation<si::power_density_t> { static constexpr char str[] = "W/m^3"; };
}
#endif
