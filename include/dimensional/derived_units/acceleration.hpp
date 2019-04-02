#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACCELERATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACCELERATION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using acceleration_t = decltype(meters * second<-2>);

inline constexpr acceleration_t acceleration{};
}

namespace mitama {
template <> struct abbreviation<si::acceleration_t> { static constexpr char str[] = "m/s^2"; };
}

#endif
