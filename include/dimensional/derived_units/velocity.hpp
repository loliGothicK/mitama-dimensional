#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VELOCITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VELOCITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using velocity_t = decltype(meters / seconds);

inline constexpr velocity_t velocity{};
}

namespace mitama {
template <> struct abbreviation<si::velocity_t> { static constexpr char str[] = "m/s"; };
}

#endif
