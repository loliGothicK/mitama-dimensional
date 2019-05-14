#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENTROPY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENTROPY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct entropy_synonym{};
using entropy_t = make_synonym_t<entropy_synonym, decltype(joule / kelvins)>;

inline constexpr entropy_t entropy{};
using entropy_r = make_refinement_symbol_t<entropy_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_CAPACITY_HPP
namespace mitama {
template <> struct abbreviation<systems::si::entropy_t> { static constexpr char str[] = "J/K"; };
}
#endif

#endif
