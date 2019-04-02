#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using area_t = powered_t<meter_t, 2>;

inline constexpr area_t area{}; 
}

#endif
