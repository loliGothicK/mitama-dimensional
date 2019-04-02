#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_ACCELERATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_ACCELERATION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "angle.hpp"

namespace mitama::si {
using angular_acceleration_t = decltype(radian / second<2>);

inline constexpr angular_acceleration_t angular_acceleration{};
}

namespace mitama {
template <> struct abbreviation<si::angular_acceleration_t> { static constexpr char str[] = "rad/s^2"; };
}
#endif
