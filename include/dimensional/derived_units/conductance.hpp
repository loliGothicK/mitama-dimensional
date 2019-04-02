#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CONDUCTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CONDUCTANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using conductance_t = decltype(kilogram<-1> * meter<-2> * second<3> * ampere<2>);

inline constexpr conductance_t siemens{}; 
}

namespace mitama {
template <> struct abbreviation<si::conductance_t> { static constexpr char str[] = "S"; };
}
#endif
