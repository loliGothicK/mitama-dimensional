#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ILLUMINANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ILLUMINANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using illuminance_t = decltype(meter<-2> * candela<>);

inline constexpr illuminance_t lux{}; 
}

namespace mitama {
template <> struct abbreviation<si::illuminance_t> { static constexpr char str[] = "lx"; };
}
#endif
