#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using action_t = decltype(meter<2> * kilogram<> * second<-1>);

inline constexpr action_t action{};
}

namespace mitama {
template <> struct abbreviation<si::action_t> { static constexpr char str[] = "J·s"; };
}

#endif
