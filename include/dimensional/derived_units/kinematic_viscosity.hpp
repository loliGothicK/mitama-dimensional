#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct kinematic_viscosity_repr{};
using kinematic_viscosity_t = make_synonym_t<kinematic_viscosity_repr, decltype(meter<2> / second<1>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP)
inline constexpr kinematic_viscosity_t kinematic_viscosity{};
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP)
namespace mitama {
template <> struct abbreviation<si::kinematic_viscosity_t> { static constexpr char str[] = "m^2/s"; };
}
#endif

#endif
