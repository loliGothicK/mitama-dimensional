#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_IRRADIANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_IRRADIANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"

namespace mitama::si {
using spectral_irradiance_t = decltype(watt / meter<3>);

inline constexpr spectral_irradiance_t spectral_irradiance{};
}

namespace mitama {
template <> struct abbreviation<si::spectral_irradiance_t> { static constexpr char str[] = "W/m^3"; };
}

#endif
