#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_POWER_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>
#include "power.hpp"

namespace mitama::systems::si {
template<class> struct spectral_power_synonym{};
using spectral_power_t = make_synonym_t<spectral_power_synonym, decltype(watt / meter<>)>;

inline constexpr spectral_power_t spectral_power{};
using spectral_power_r = make_refinement_symbol_t<spectral_power_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::spectral_power_t> { static constexpr char str[] = "W/m"; };
}

#endif
