#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRICAL_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRICAL_CONDUCTIVITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>
#include "conductance.hpp"

namespace mitama::systems::si {
template<class> struct electrical_conductivity_synonym{};
using electrical_conductivity_t = make_synonym_t<electrical_conductivity_synonym, decltype(siemens / meter<>)>;

inline constexpr electrical_conductivity_t electrical_conductivity{};
using electrical_conductivity_r = make_refinement_symbol_t<electrical_conductivity_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::electrical_conductivity_t> { static constexpr char str[] = "S/m"; };
}
#endif
