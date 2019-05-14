#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_VECTOR_POTENTIAL_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_VECTOR_POTENTIAL_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "magnetic_flux.hpp"

namespace mitama::systems::si {
template<class> struct magnetic_vector_potential_synonym{};
using magnetic_vector_potential_t = make_synonym_t<magnetic_vector_potential_synonym, decltype(weber / meter<>)>;

inline constexpr magnetic_vector_potential_t magnetic_vector_potential{};
using magnetic_vector_potential_r = make_refinement_symbol_t<magnetic_vector_potential_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::magnetic_vector_potential_t> { static constexpr char str[] = "Wb/m"; };
}
#endif
