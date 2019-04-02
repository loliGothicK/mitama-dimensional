#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ABSORBED_DOSE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ABSORBED_DOSE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using absorbed_dose_t = decltype(meter<2> * second<-2>);

inline constexpr absorbed_dose_t gray{}; 
}

namespace mitama {
template <> struct abbreviation<si::absorbed_dose_t> { static constexpr char str[] = "Gy"; };
}
#endif
