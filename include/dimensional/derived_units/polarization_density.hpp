#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POLARIZATION_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POLARIZATION_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "electric_charge.hpp"

namespace mitama::si {
template<class> struct polarization_density_repr{};
using polarization_density_t = make_synonym_t<polarization_density_repr, decltype(coulomb / meter<2>)>;

inline constexpr polarization_density_t polarization_density{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_DISPLACEMENT_FIELD_HPP
namespace mitama {
template <> struct abbreviation<si::polarization_density_t> { static constexpr char str[] = "C/m^2"; };
}
#endif

#endif
