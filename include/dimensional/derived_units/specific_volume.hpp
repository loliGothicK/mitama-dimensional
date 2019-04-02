#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_VOLUME_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_VOLUME_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using specific_volume_t = decltype(meter<3> / kilogram<>);

inline constexpr specific_volume_t specific_volume{};
}

namespace mitama {
template <> struct abbreviation<si::specific_volume_t> { static constexpr char str[] = "m^3/kg"; };
}

#endif
