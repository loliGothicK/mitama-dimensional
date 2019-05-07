#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_CAPACITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_CAPACITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "energy.hpp"


namespace mitama::si {
template<class> struct heat_capacity_synonym{};
using heat_capacity_t = make_synonym_t<heat_capacity_synonym, decltype(joule / kelvins)>;

inline constexpr heat_capacity_t heat_capacity{};
using heat_capacity_r = make_refinement_symbol_t<heat_capacity_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENTROPY_HPP
namespace mitama {
template <> struct abbreviation<si::heat_capacity_t> { static constexpr char str[] = "J/K"; };
}
#endif

#endif
