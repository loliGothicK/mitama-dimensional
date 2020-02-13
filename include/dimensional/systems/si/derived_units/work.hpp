#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct work_synonym{};
using work_t = make_synonym_t<work_synonym, decltype(kilogram<> * meter<2> * second<-2>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP)
inline constexpr work_t joule{};

#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP)
namespace mitama {
template <> struct  abbreviation_<systems::si::work_t> { static constexpr char str[] = "J"; };
}
#endif

#endif