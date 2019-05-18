#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_FIELD_STRENGTH_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_FIELD_STRENGTH_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "voltage.hpp"

namespace mitama::systems::si {
template<class> struct electric_field_strength_synonym{};
using electric_field_strength_t = make_synonym_t<electric_field_strength_synonym, decltype(volts / meters)>;

inline constexpr electric_field_strength_t electric_field_strength{};
using electric_field_strength_r = make_refinement_symbol_t<electric_field_strength_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::electric_field_strength_t> { static constexpr char str[] = "V/m"; };
}
#endif
