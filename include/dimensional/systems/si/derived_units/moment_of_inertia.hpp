#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENT_OF_INERTIA_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENT_OF_INERTIA_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct moment_of_inertia_synonym{};
using moment_of_inertia_t = make_synonym_t<moment_of_inertia_synonym, decltype(kilogram<> * meter<2>)>;

inline constexpr moment_of_inertia_t moment_of_inertia{};
using moment_of_inertia_r = make_refinement_symbol_t<moment_of_inertia_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::moment_of_inertia_t> { static constexpr char str[] = "kg m^2"; };
}

#endif
