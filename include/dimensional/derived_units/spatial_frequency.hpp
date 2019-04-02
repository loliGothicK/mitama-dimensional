#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPATIAL_FREQUENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPATIAL_FREQUENCY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using spatial_frequency_t = reciprocal_t<meter_t>;

inline constexpr spatial_frequency_t spatial_frequency{};
}

#endif
