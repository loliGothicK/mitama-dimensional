#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_STIFFNESS_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_STIFFNESS_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "./force.hpp"

namespace mitama::systems::si {
template<class> struct stiffness_synonym{};
using stiffness_t = make_synonym_t<stiffness_synonym, decltype(newton / meter<>)>;

inline constexpr stiffness_t stiffness{};
using stiffness_r = make_refinement_symbol_t<stiffness_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::stiffness_t> { static constexpr char str[] = "N/m"; };
}
#endif
