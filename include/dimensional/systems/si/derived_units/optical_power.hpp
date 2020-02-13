#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_OPTICAL_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_OPTICAL_POWER_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
using optical_power_t = reciprocal_t<meter_t>;

inline constexpr optical_power_t optical_power{};

}

#endif
