#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPEDANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPEDANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct impedance_repr{};
using impedance_t = make_synonym_t<impedance_repr, decltype(kilogram<> * meter<2> * second<-3> * ampere<-2>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP)
inline constexpr impedance_t ohm{};
using impedance_r = make_refiment_symbol_t<impedance_t>;
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTANCE_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_REACTANCE_HPP)
namespace mitama {
template <> struct abbreviation<si::impedance_t> { static constexpr char str[] = "Ω"; };
}
#endif

#endif
