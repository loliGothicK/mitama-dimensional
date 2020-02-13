#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct thermal_diffusivity_synonym{};
using thermal_diffusivity_t = make_synonym_t<thermal_diffusivity_synonym, decltype(meter<2> / second<1>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP)
inline constexpr thermal_diffusivity_t thermal_diffusivity{};

#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP)
namespace mitama {
template <> struct  abbreviation_<systems::si::thermal_diffusivity_t> { static constexpr char str[] = "m^2/s"; };
}
#endif

#endif
