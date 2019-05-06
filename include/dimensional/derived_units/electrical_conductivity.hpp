#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRICAL_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRICAL_CONDUCTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "conductance.hpp"

namespace mitama::si {
template<class> struct electrical_conductivity_repr{};
using electrical_conductivity_t = make_synonym_t<electrical_conductivity_repr, decltype(siemens / meter<>)>;

inline constexpr electrical_conductivity_t electrical_conductivity{};
using electrical_conductivity_r = make_refinement_symbol_t<electrical_conductivity_t>;
}

namespace mitama {
template <> struct abbreviation<si::electrical_conductivity_t> { static constexpr char str[] = "S/m"; };
}
#endif
