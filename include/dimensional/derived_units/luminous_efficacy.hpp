#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EFFICACY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EFFICACY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"
#include "luminous_flux.hpp"

namespace mitama::si {
using luminous_efficacy_t = decltype(lumen / watt);

inline constexpr luminous_efficacy_t luminous_efficacy{};
}

namespace mitama {
template <> struct abbreviation<si::luminous_efficacy_t> { static constexpr char str[] = "lm/W"; };
}
#endif
