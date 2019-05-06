#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct heat_repr{};
using heat_t = make_synonym_t<heat_repr, decltype(kilogram<> * meter<2> * second<-2>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP)
inline constexpr heat_t joule{};
using heat_r = make_refinement_symbol_t<heat_t>;
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP)
namespace mitama {
template <> struct abbreviation<si::heat_t> { static constexpr char str[] = "J"; };
}
#endif

#endif