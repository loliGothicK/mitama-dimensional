#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_VELOCITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_VELOCITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "angle.hpp"


namespace mitama::si {
using angular_velocity_t = decltype(radian / seconds);

inline constexpr angular_velocity_t angular_velocity{};
}

namespace mitama {
template <> struct abbreviation<si::angular_velocity_t> { static constexpr char str[] = "rad/s"; };
}
#endif
