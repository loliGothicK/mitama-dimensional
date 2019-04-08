#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_TORQUE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_TORQUE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "force.hpp"

namespace mitama::si {
template<class> struct torque_repr{};
using torque_t = make_synonym_t<torque_repr, decltype(newton * meters)>;

inline constexpr torque_t torque{};
}

namespace mitama {
template <> struct abbreviation<si::torque_t> { static constexpr char str[] = "N·m"; };
}

#endif
