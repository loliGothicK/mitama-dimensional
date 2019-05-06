#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_CONDUCTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "conductance.hpp"

namespace mitama::si {
template<class> struct molar_conductivity_repr{};
using molar_conductivity_t = make_synonym_t<molar_conductivity_repr, decltype(siemens * meter<2> / mol<>)>;

inline constexpr molar_conductivity_t molar_conductivity{};
using molar_conductivity_r = make_refinement_symbol_t<molar_conductivity_t>;
}

namespace mitama {
template <> struct abbreviation<si::molar_conductivity_t> { static constexpr char str[] = "S·m^2/mol"; };
}
#endif
