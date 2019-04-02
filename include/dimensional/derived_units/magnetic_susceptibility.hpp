#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_SUSCEPTIBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_SUSCEPTIBILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "inductance.hpp"

namespace mitama::si {
using magnetic_susceptibility_t = decltype(meter<> / henry);

inline constexpr magnetic_susceptibility_t magnetic_susceptibility{};
}

namespace mitama {
template <> struct abbreviation<si::magnetic_susceptibility_t> { static constexpr char str[] = "m/H"; };
}
#endif
