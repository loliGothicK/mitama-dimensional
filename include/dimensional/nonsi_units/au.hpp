#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_AU_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_AU_HPP
#include "../si_units/meter.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::nonsi {
using au_t = scaled_unit_t<si::meter_t, std::ratio<149'597'870'700>>;
inline constexpr au_t au{};
}

namespace mitama {
template <> struct abbreviation<nonsi::au_t> { static constexpr char str[] = "au"; };
}

#endif