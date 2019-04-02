#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_FLUX_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "solid_angle.hpp"

namespace mitama::si {
using luminous_flux_t = decltype(candela<> * steradian);

inline constexpr luminous_flux_t lumen{}; 
}

namespace mitama {
template <> struct abbreviation<si::luminous_flux_t> { static constexpr char str[] = "lm"; };
}
#endif
