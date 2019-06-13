#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_ENERGY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "luminous_flux.hpp"

namespace mitama::systems::si {
template<class> struct luminous_energy_synonym{};
using luminous_energy_t = make_synonym_t<luminous_energy_synonym, decltype(lumen * second<>)>;

inline constexpr luminous_energy_t luminous_energy{};
using luminous_energy_r = make_refinement_symbol_t<luminous_energy_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::luminous_energy_t> { static constexpr char str[] = "lm s"; };
}
#endif
