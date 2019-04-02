#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"

namespace mitama::si {
using heat_flux_density_t = decltype(watt / meter<2>);

inline constexpr heat_flux_density_t heat_flux_density{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IRRADIANCE_HPP
namespace mitama {
template <> struct abbreviation<si::heat_flux_density_t> { static constexpr char str[] = "W/m^2"; };
}
#endif


#endif
