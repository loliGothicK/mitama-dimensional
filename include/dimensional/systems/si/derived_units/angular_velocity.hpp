#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_VELOCITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_VELOCITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "angle.hpp"


namespace mitama::systems::si {
template<class> struct angular_velocity_synonym{};
using angular_velocity_t = make_synonym_t<angular_velocity_synonym, decltype(radian / seconds)>;

inline constexpr angular_velocity_t angular_velocity{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::angular_velocity_t> { static constexpr char str[] = "rad/s"; };
}
#endif
