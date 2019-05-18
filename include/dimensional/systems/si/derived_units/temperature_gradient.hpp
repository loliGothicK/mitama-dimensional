#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_TEMPERATURE_GRADIENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_TEMPERATURE_GRADIENT_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct temperature_gradient_synonym{};
using temperature_gradient_t = make_synonym_t<temperature_gradient_synonym, decltype(kelvin<> / meter<>)>;

inline constexpr temperature_gradient_t temperature_gradient{};
using temperature_gradient_r = make_refinement_symbol_t<temperature_gradient_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::temperature_gradient_t> { static constexpr char str[] = "K/m"; };
}

#endif
