#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PASCAL_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PASCAL_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::si {
using pressure_t = decltype(kilogram<> * meter<-1> * second<-2>);
inline constexpr pressure_t pascal{}; 
}

namespace mitama {
template <> struct abbreviation<si::pressure_t> { static constexpr char str[] = "Pa"; };
}
#endif