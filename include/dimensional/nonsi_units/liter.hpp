#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_LITRE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_LITRE_HPP
#include "../si_units/meter.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::nonsi {

using litre_t = powered_t<scaled_unit_t<si::meter_t, std::deci>, 3>;
inline constexpr litre_t litre{};
using liter_t = powered_t<scaled_unit_t<si::meter_t, std::deci>, 3>;
inline constexpr liter_t liter{};
}

namespace mitama {
template <> struct abbreviation<nonsi::litre_t> { static constexpr char str[] = "L"; };
}

#endif