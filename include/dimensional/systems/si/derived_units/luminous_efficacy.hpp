#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EFFICACY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EFFICACY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "power.hpp"
#include "luminous_flux.hpp"

namespace mitama::systems::si {
template<class> struct luminous_efficacy_synonym{};
using luminous_efficacy_t = make_synonym_t<luminous_efficacy_synonym, decltype(lumen / watt)>;

inline constexpr luminous_efficacy_t luminous_efficacy{};
using luminous_efficacy_r = make_refinement_symbol_t<luminous_efficacy_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::luminous_efficacy_t> { static constexpr char str[] = "lm/W"; };
}
#endif
