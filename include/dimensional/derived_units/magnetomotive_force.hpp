#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETOMOTIVE_FORCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETOMOTIVE_FORCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "angle.hpp"

namespace mitama::si {
using magnetomotive_force_t = decltype(ampere<> * radian);

inline constexpr magnetomotive_force_t magnetomotive_force{};
}

namespace mitama {
template <> struct abbreviation<si::magnetomotive_force_t> { static constexpr char str[] = "A·rad"; };
}

#endif
