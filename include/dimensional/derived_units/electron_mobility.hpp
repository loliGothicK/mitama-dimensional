#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRON_MOBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRON_MOBILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "voltage.hpp"

namespace mitama::si {
using electron_mobility_t = decltype( meter<2> * volt<-1> * second<-1> );

inline constexpr electron_mobility_t electron_mobility{};
}

namespace mitama {
template <> struct abbreviation<si::electron_mobility_t> { static constexpr char str[] = "m^2/(V·s)"; };
}
#endif
