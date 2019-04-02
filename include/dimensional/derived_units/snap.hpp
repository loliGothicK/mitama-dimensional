#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SNAP_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SNAP_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using snap_t = decltype(meters * second<-4>);

inline constexpr snap_t snap{};
}

namespace mitama {
template <> struct abbreviation<si::snap_t> { static constexpr char str[] = "m/s^4"; };
}

#endif
