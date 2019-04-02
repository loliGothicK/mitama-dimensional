#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IRRADIANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_IRRADIANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"

namespace mitama::si {
using irradiance_t = decltype(watt * meter<-2>);

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_DENSITY_HPP
inline constexpr irradiance_t irradiance{};
#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_DENSITY_HPP
namespace mitama {
template <> struct abbreviation<si::irradiance_t> { static constexpr char str[] = "W/m^2"; };
}
#endif

#endif
