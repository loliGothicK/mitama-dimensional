#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_TORQUE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_TORQUE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "force.hpp"

namespace mitama::systems::si {
template<class> struct torque_synonym{};
using torque_t = make_synonym_t<torque_synonym, decltype(newton * meters)>;

inline constexpr torque_t torque{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::torque_t> { static constexpr char str[] = "N m"; };
}

#endif
