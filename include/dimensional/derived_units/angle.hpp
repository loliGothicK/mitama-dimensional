#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGLE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGLE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::si {
struct angle { using is_base_dimension = void; };
using radian_t = make_unit_t<angle>;
inline constexpr radian_t radian{};
}

namespace mitama {
template <> struct symbol_<si::angle> { static constexpr char str[] = "rad"; };
}
#endif