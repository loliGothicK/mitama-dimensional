#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_POWER_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "power.hpp"

namespace mitama::si {
template<class> struct spectral_power_repr{};
using spectral_power_t = make_synonym_t<spectral_power_repr, decltype(watt / meter<>)>;

inline constexpr spectral_power_t spectral_power{};
using spectral_power_r = make_refinement_symbol_t<spectral_power_t>;
}

namespace mitama {
template <> struct abbreviation<si::spectral_power_t> { static constexpr char str[] = "W/m"; };
}

#endif
