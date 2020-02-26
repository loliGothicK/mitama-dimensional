#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
using area_t = powered_t<meter_t, 2>;

inline constexpr area_t area{};

}

#endif
