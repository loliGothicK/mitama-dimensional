#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct heat_synonym{};
using heat_t = make_synonym_t<heat_synonym, decltype(kilogram<> * meter<2> * second<-2>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP)
inline constexpr heat_t joule{};
using heat_r = make_refinement_symbol_t<heat_t>;
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP)
namespace mitama {
template <> struct  abbreviation_<systems::si::heat_t> { static constexpr char str[] = "J"; };
}
#endif

#endif