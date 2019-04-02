#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_EXPOSURE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_EXPOSURE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "electric_charge.hpp"

namespace mitama::si {
using exposure_t = decltype(coulomb / kilogram<>);

inline constexpr exposure_t exposure{};
}

namespace mitama {
template <> struct abbreviation<si::exposure_t> { static constexpr char str[] = "C/kg"; };
}
#endif
