#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PASCAL_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PASCAL_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
template<class> struct pressure_synonym{};
using pressure_t = make_synonym_t<pressure_synonym, decltype(kilogram<> * meter<-1> * second<-2>)>;
inline constexpr pressure_t pascal{};
using pressure_r = make_refinement_symbol_t<pressure_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::pressure_t> { static constexpr char str[] = "Pa"; };
}
#endif