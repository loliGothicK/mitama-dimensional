#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FORCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FORCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
template<class> struct force_synonym{};
using force_t = make_synonym_t<force_synonym, decltype(kilogram<> * meter<> * second<-2>)>;
#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WEIGHT_HPP
inline constexpr force_t newton{};
using force_r = make_refinement_symbol_t<force_t>;
#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WEIGHT_HPP
namespace mitama {
template <> struct abbreviation<systems::si::force_t> { static constexpr char str[] = "N"; };
}
#endif

#endif