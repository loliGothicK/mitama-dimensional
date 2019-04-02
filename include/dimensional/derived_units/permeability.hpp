#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "inductance.hpp"

namespace mitama::si {
using permeability_t = decltype(henry / meter<>);

inline constexpr permeability_t permeability{};
}

namespace mitama {
template <> struct abbreviation<si::permeability_t> { static constexpr char str[] = "H/m"; };
}
#endif
