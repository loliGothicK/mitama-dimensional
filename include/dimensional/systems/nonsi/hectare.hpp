#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_HECTARE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_HECTARE_HPP
#include <dimensional/systems/si/meter.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::nonsi {
using hectare_t = powered_t<scaled_unit_t<systems::si::meter_t, std::hecto>, 2>;
inline constexpr hectare_t hectare{};

}

namespace mitama {
template <> struct abbreviation<systems::nonsi::hectare_t> { static constexpr char str[] = "ha"; };
}

#endif