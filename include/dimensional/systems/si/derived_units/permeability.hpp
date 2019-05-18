#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "inductance.hpp"

namespace mitama::systems::si {
template<class> struct permeability_synonym{};
using permeability_t = make_synonym_t<permeability_synonym, decltype(henry / meter<>)>;

inline constexpr permeability_t permeability{};
using permeability_r = make_refinement_symbol_t<permeability_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::permeability_t> { static constexpr char str[] = "H/m"; };
}
#endif
