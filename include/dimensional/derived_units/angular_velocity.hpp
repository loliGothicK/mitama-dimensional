#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_VELOCITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_VELOCITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "angle.hpp"


namespace mitama::si {
template<class> struct angular_velocity_synonym{};
using angular_velocity_t = make_synonym_t<angular_velocity_synonym, decltype(radian / seconds)>;

inline constexpr angular_velocity_t angular_velocity{};
using angular_velocity_r = make_refinement_symbol_t<angular_velocity_t>;
}

namespace mitama {
template <> struct abbreviation<si::angular_velocity_t> { static constexpr char str[] = "rad/s"; };
}
#endif
