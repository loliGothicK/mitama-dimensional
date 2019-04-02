#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using area_density_t = decltype(meter<-2> * kilogram<>);

inline constexpr area_density_t area_density{};
}

namespace mitama {
template <> struct abbreviation<si::area_density_t> { static constexpr char str[] = "kg/m^2"; };
}

#endif
