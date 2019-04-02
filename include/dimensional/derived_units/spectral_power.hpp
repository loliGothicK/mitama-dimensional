#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_POWER_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"

namespace mitama::si {
using spectral_power_t = decltype(watt / meter<>);

inline constexpr spectral_power_t spectral_power{};
}

namespace mitama {
template <> struct abbreviation<si::spectral_power_t> { static constexpr char str[] = "W/m"; };
}

#endif
