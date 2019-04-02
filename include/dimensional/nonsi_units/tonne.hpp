#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_TONNE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_TONNE_HPP
#include "../si_units/kilogram.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::nonsi {
using tonne_t = scaled_unit_t<si::kilogram_t, std::ratio<1000>>;
inline constexpr tonne_t tonne{};
}

namespace mitama {
template <> struct abbreviation<nonsi::tonne_t> { static constexpr char str[] = "t"; };
}

#endif