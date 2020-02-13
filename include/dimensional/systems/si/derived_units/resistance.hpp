#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct resistance_synonym{};
using resistance_t = make_synonym_t<resistance_synonym, decltype(kilogram<> * meter<2> * second<-3> * ampere<-2>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP)
inline constexpr resistance_t ohm{};

#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP)
namespace mitama {
template <> struct  abbreviation_<systems::si::resistance_t> { static constexpr char str[] = "Ω"; };
}
#endif

#endif
