#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_HEAT_CAPACITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_HEAT_CAPACITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "energy.hpp"


namespace mitama::si {
using specific_heat_capacity_t = decltype( joule * kilogram<-1> * kelvin<-1> );

inline constexpr specific_heat_capacity_t specific_heat_capacity{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENTROPY_HPP
namespace mitama {
template <> struct abbreviation<si::specific_heat_capacity_t> { static constexpr char str[] = "J/(K·kg)"; };
}
#endif

#endif
