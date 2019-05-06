#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct thermal_diffusivity_repr{};
using thermal_diffusivity_t = make_synonym_t<thermal_diffusivity_repr, decltype(meter<2> / second<1>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP)
inline constexpr thermal_diffusivity_t thermal_diffusivity{};
using thermal_diffusivity_r = make_refinement_symbol_t<thermal_diffusivity_t>;
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP)
namespace mitama {
template <> struct abbreviation<si::thermal_diffusivity_t> { static constexpr char str[] = "m^2/s"; };
}
#endif

#endif
