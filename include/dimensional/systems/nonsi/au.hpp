#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_AU_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_AU_HPP
#include <dimensional/systems/si/base_units/meter.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::nonsi {
using au_t = scaled_unit_t<systems::si::meter_t, std::ratio<149'597'870'700>>;
inline constexpr au_t au{};
}

namespace mitama {
template <> struct  abbreviation_<systems::nonsi::au_t> { static constexpr char str[] = "au"; };
}

#endif