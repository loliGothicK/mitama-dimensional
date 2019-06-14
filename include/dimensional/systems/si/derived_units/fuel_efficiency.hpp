#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FUEL_EFFICIENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FUEL_EFFICIENCY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct fuel_efficiency_synonym{};
using fuel_efficiency_t = make_synonym_t<fuel_efficiency_synonym, decltype(meter<-2>)>;

inline constexpr fuel_efficiency_t fuel_efficiency{};
using fuel_efficiency_r = make_refinement_symbol_t<fuel_efficiency_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::fuel_efficiency_t> { static constexpr char str[] = "m/m^3"; };
}

#endif
