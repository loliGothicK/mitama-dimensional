#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_LITRE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_LITRE_HPP
#include <dimensional/systems/si/meter.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::nonsi {

using litre_t = powered_t<scaled_unit_t<systems::si::meter_t, std::deci>, 3>;
inline constexpr litre_t litre{};
using liter_t = powered_t<scaled_unit_t<systems::si::meter_t, std::deci>, 3>;
inline constexpr liter_t liter{};
}

namespace mitama {
template <> struct  abbreviation_<systems::nonsi::litre_t> { static constexpr char str[] = "L"; };
}

#endif