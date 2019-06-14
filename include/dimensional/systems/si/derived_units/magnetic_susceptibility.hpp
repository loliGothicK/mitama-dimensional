#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_SUSCEPTIBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_SUSCEPTIBILITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "inductance.hpp"

namespace mitama::systems::si {
template<class> struct magnetic_susceptibility_synonym{};
using magnetic_susceptibility_t = make_synonym_t<magnetic_susceptibility_synonym, decltype(meter<> / henry)>;

inline constexpr magnetic_susceptibility_t magnetic_susceptibility{};
using magnetic_susceptibility_r = make_refinement_symbol_t<magnetic_susceptibility_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::magnetic_susceptibility_t> { static constexpr char str[] = "m/H"; };
}
#endif
