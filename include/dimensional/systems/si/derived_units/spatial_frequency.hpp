#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPATIAL_FREQUENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPATIAL_FREQUENCY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
using spatial_frequency_t = reciprocal_t<meter_t>;

inline constexpr spatial_frequency_t spatial_frequency{};

}

#endif
