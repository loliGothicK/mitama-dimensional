#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_RADIANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_RADIANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "power.hpp"
#include "solid_angle.hpp"

namespace mitama::si {
template<class> struct spectral_radiance_synonym{};
using spectral_radiance_t = make_synonym_t<spectral_radiance_synonym, decltype( watt / (steradian * meter<3>) )>;

inline constexpr spectral_radiance_t spectral_radiance{};
using spectral_radiance_r = make_refinement_symbol_t<spectral_radiance_t>;
}

namespace mitama {
template <> struct abbreviation<si::spectral_radiance_t> { static constexpr char str[] = "W/(sr·m^3)"; };
}
#endif
