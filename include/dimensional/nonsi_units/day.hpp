#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_DAY_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_DAY_HPP
#include "../si_units/second.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::nonsi {
using day_t = scaled_unit_t<si::second_t, std::ratio<24*60*60>>;
inline constexpr day_t days{};
}

namespace mitama {
template <> struct abbreviation<nonsi::day_t> { static constexpr char str[] = "d"; };
}

#endif