#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPEDANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPEDANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct impedance_synonym{};
using impedance_t = make_synonym_t<impedance_synonym, decltype(kilogram<> * meter<2> * second<-3> * ampere<-2>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP)
inline constexpr impedance_t ohm{};
using impedance_r = make_refinement_symbol_t<impedance_t>;
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP)
namespace mitama {
template <> struct  abbreviation_<systems::si::impedance_t> { static constexpr char str[] = "Ω"; };
}
#endif

#endif
