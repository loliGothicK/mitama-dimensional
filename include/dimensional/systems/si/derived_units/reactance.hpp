#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct reactance_synonym{};
using reactance_t = make_synonym_t<reactance_synonym, decltype(kilogram<> * meter<2> * second<-3> * ampere<-2>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPEDANCE_HPP)
inline constexpr reactance_t ohm{};

#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPEDANCE_HPP)
namespace mitama {
template <> struct  abbreviation_<systems::si::reactance_t> { static constexpr char str[] = "Ω"; };
}
#endif

#endif
