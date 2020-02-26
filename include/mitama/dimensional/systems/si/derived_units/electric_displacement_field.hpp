#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_DISPLACEMENT_FIELD_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_DISPLACEMENT_FIELD_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "electric_charge.hpp"

namespace mitama::systems::si {
template<class> struct electric_displacement_field_synonym{};
using electric_displacement_field_t = make_synonym_t<electric_displacement_field_synonym, decltype(coulomb / meter<2>)>;

inline constexpr electric_displacement_field_t electric_displacement_field{};

}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POLARIZATION_DENSITY_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::electric_displacement_field_t> { static constexpr char str[] = "C/m^2"; };
}
#endif

#endif
