#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTION_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct action_synonym{};
using action_t = make_synonym_t<action_synonym, decltype(meter<2> * kilogram<> * second<-1>)>;

inline constexpr action_t action{};
using action_r = make_refinement_symbol_t<action_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::action_t> { static constexpr char str[] = "J·s"; };
}

#endif
