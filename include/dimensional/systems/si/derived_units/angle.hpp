#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGLE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGLE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
struct angle {
    using is_base_dimension = void;
    using is_dimensionless = void;
};
using radian_t = make_unit_t<angle>;
inline constexpr radian_t radian{};
using radian_r = make_refinement_symbol_t<radian_t>;
}

namespace mitama {
template <> struct symbol_<systems::si::angle> { static constexpr char str[] = "rad"; };
}
#endif