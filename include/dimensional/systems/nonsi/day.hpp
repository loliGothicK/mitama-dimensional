#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_DAY_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_DAY_HPP
#include <dimensional/systems/si/second.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::nonsi {
using day_t = scaled_unit_t<systems::si::second_t, std::ratio<24*60*60>>;
inline constexpr day_t days{};
}

namespace mitama {
template <> struct  abbreviation_<systems::nonsi::day_t> { static constexpr char str[] = "d"; };
}

#endif