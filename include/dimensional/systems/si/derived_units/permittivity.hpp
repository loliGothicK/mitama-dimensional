#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMITTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMITTIVITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "capacitance.hpp"

namespace mitama::systems::si {
template<class> struct permittivity_synonym{};
using permittivity_t = make_synonym_t<permittivity_synonym, decltype(farad / meter<>)>;

inline constexpr permittivity_t permittivity{};
using permittivity_r = make_refinement_symbol_t<permittivity_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::permittivity_t> { static constexpr char str[] = "F/m"; };
}
#endif
