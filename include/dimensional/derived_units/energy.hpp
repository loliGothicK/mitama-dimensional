#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using energy_t = decltype(kilogram<> * meter<2> * second<-2>);

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP)
inline constexpr energy_t joule{}; 
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP)
namespace mitama {
template <> struct abbreviation<si::energy_t> { static constexpr char str[] = "J"; };
}
#endif

#endif