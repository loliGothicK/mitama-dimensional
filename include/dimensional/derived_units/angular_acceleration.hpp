#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_ACCELERATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_ACCELERATION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "angle.hpp"

namespace mitama::si {
template<class> struct angular_acceleration_repr{};
using angular_acceleration_t = make_synonym_t<angular_acceleration_repr, decltype(radian / second<2>)>;

inline constexpr angular_acceleration_t angular_acceleration{};
using angular_acceleration_r = make_refiment_symbol_t<angular_acceleration_t>;
}

namespace mitama {
template <> struct abbreviation<si::angular_acceleration_t> { static constexpr char str[] = "rad/s^2"; };
}
#endif
