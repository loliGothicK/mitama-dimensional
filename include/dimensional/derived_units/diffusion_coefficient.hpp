#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using diffusion_coefficient_t = decltype(meter<2> / second<1>);

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP)
inline constexpr diffusion_coefficient_t diffusion_coefficient{};
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP)
namespace mitama {
template <> struct abbreviation<si::diffusion_coefficient_t> { static constexpr char str[] = "m^2/s"; };
}
#endif

#endif
