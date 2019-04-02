#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_TORQUE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_TORQUE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "force.hpp"

namespace mitama::si {
using torque_t = decltype(newton * meters);

inline constexpr torque_t torque{};
}

namespace mitama {
template <> struct abbreviation<si::torque_t> { static constexpr char str[] = "N·m"; };
}

#endif
