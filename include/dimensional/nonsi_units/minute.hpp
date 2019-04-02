#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_MUNUTE_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_MUNUTE_HPP
#include "../si_units/second.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::nonsi {
using minute_t = scaled_unit_t<si::second_t, std::ratio<60>>;
inline constexpr minute_t minutes{};
}

namespace mitama {
template <> struct abbreviation<nonsi::minute_t> { static constexpr char str[] = "m"; };
}

#endif