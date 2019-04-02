#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUME_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUME_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using volume_t = powered_t<meter_t, 3>;

inline constexpr volume_t volume{}; 
}

#endif
