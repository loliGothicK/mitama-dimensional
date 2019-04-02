#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FUEL_EFFICIENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FUEL_EFFICIENCY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using fuel_efficiency_t = decltype(meter<-2>);

inline constexpr fuel_efficiency_t fuel_efficiency{};
}

namespace mitama {
template <> struct abbreviation<si::fuel_efficiency_t> { static constexpr char str[] = "m/m^3"; };
}

#endif
