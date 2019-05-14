#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SOLID_ANGLE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SOLID_ANGLE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
struct solid_angle {
    using is_base_dimension = void;
    using is_dimensionless = void;
};
using steradian_t = make_unit_t<solid_angle>;
inline constexpr steradian_t steradian{};
using steradian_r = make_refinement_symbol_t<steradian_t>;
}

namespace mitama {
template <> struct symbol_<systems::si::solid_angle> { static constexpr char str[] = "sr"; };
}
#endif