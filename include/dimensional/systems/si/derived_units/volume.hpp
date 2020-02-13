#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUME_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLUME_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
using volume_t = powered_t<meter_t, 3>;

inline constexpr volume_t volume{};

}

#endif
