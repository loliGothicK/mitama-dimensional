#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENERGY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "energy.hpp"

namespace mitama::si {
template<class> struct specific_energy_synonym{};
using specific_energy_t = make_synonym_t<specific_energy_synonym, decltype(joule / kilogram<>)>;

inline constexpr specific_energy_t specific_energy{};
using specific_energy_r = make_refinement_symbol_t<specific_energy_t>;
}

namespace mitama {
template <> struct abbreviation<si::specific_energy_t> { static constexpr char str[] = "J/kg"; };
}
#endif
