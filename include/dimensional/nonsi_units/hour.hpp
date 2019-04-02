#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_HOUR_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_HOUR_HPP
#include "../si_units/second.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::nonsi {
using hour_t = scaled_unit_t<si::second_t, std::ratio<60*60>>;
inline constexpr hour_t hours{};
}

namespace mitama {
template <> struct abbreviation<nonsi::hour_t> { static constexpr char str[] = "h"; };
}

#endif