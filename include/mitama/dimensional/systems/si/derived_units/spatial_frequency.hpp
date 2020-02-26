#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPATIAL_FREQUENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPATIAL_FREQUENCY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
using spatial_frequency_t = reciprocal_t<meter_t>;

inline constexpr spatial_frequency_t spatial_frequency{};

}

#endif
