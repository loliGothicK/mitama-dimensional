#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using reactance_t = decltype(kilogram<> * meter<2> * second<-3> * ampere<-2>);

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPEDANCE_HPP)
inline constexpr reactance_t ohm{}; 
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPEDANCE_HPP)
namespace mitama {
template <> struct abbreviation<si::reactance_t> { static constexpr char str[] = "Ω"; };
}
#endif

#endif
