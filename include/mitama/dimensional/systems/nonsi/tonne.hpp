#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_TONNE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_TONNE_HPP
#include <mitama/dimensional/systems/si/base_units/kilogram.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

namespace mitama::systems::nonsi {
using tonne_t = scaled_unit_t<systems::si::kilogram_t, std::ratio<1000>>;
inline constexpr tonne_t tonne{};
}

namespace mitama {
template <> struct  abbreviation_<systems::nonsi::tonne_t> { static constexpr char str[] = "t"; };
}

#endif