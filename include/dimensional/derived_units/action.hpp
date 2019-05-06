#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct action_synonym{};
using action_t = make_synonym_t<action_synonym, decltype(meter<2> * kilogram<> * second<-1>)>;

inline constexpr action_t action{};
using action_r = make_refinement_symbol_t<action_t>;
}

namespace mitama {
template <> struct abbreviation<si::action_t> { static constexpr char str[] = "J·s"; };
}

#endif
