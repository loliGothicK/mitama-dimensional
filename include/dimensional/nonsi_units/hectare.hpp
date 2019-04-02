#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_HECTARE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_HECTARE_HPP
#include "../si_units/meter.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::nonsi {
using hectare_t = powered_t<scaled_unit_t<si::meter_t, std::hecto>, 2>;
inline constexpr hectare_t hectare{};

}

namespace mitama {
template <> struct abbreviation<nonsi::hectare_t> { static constexpr char str[] = "ha"; };
}

#endif