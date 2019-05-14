#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_TONNE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_TONNE_HPP
#include <dimensional/systems/si/kilogram.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::nonsi {
using tonne_t = scaled_unit_t<systems::si::kilogram_t, std::ratio<1000>>;
inline constexpr tonne_t tonne{};
}

namespace mitama {
template <> struct abbreviation<systems::nonsi::tonne_t> { static constexpr char str[] = "t"; };
}

#endif