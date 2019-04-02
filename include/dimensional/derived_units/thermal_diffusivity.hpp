#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using thermal_diffusivity_t = decltype(meter<2> / second<1>);

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP)
inline constexpr thermal_diffusivity_t thermal_diffusivity{};
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP)
namespace mitama {
template <> struct abbreviation<si::thermal_diffusivity_t> { static constexpr char str[] = "m^2/s"; };
}
#endif

#endif
