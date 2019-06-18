#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SOLID_ANGLE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SOLID_ANGLE_HPP
#include <dimensional/systems/si/base_dimension/solid_angle.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
using steradian_base_unit = base_units<solid_angle, 0>;
using steradian_t = typename steradian_base_unit::unit_type;
inline constexpr steradian_t steradian{};
using steradian_r = make_refinement_symbol_t<steradian_t>;
}

namespace mitama {
template <> struct symbol_<systems::si::solid_angle, 0> { static constexpr char str[] = "sr"; };
}
#endif
