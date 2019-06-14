#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_ACCELERATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_ACCELERATION_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "angle.hpp"

namespace mitama::systems::si {
template<class> struct angular_acceleration_synonym{};
using angular_acceleration_t = make_synonym_t<angular_acceleration_synonym, decltype(radian / second<2>)>;

inline constexpr angular_acceleration_t angular_acceleration{};
using angular_acceleration_r = make_refinement_symbol_t<angular_acceleration_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::angular_acceleration_t> { static constexpr char str[] = "rad/s^2"; };
}
#endif
