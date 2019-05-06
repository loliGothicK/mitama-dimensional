#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_DISPLACEMENT_FIELD_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_DISPLACEMENT_FIELD_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "electric_charge.hpp"

namespace mitama::si {
template<class> struct electric_displacement_field_synonym{};
using electric_displacement_field_t = make_synonym_t<electric_displacement_field_synonym, decltype(coulomb / meter<2>)>;

inline constexpr electric_displacement_field_t electric_displacement_field{};
using electric_displacement_field_r = make_refinement_symbol_t<electric_displacement_field_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POLARIZATION_DENSITY_HPP
namespace mitama {
template <> struct abbreviation<si::electric_displacement_field_t> { static constexpr char str[] = "C/m^2"; };
}
#endif

#endif
