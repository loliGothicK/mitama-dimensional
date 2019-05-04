#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_IRRADIANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_IRRADIANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "power.hpp"

namespace mitama::si {
template<class> struct spectral_irradiance_repr{};
using spectral_irradiance_t = make_synonym_t<spectral_irradiance_repr, decltype(watt / meter<3>)>;

inline constexpr spectral_irradiance_t spectral_irradiance{};
using spectral_irradiance_r = make_refiment_symbol_t<spectral_irradiance_t>;
}

namespace mitama {
template <> struct abbreviation<si::spectral_irradiance_t> { static constexpr char str[] = "W/m^3"; };
}

#endif
