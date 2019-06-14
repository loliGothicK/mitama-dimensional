#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct area_density_synonym{};
using area_density_t = make_synonym_t<area_density_synonym, decltype(meter<-2> * kilogram<>)>;

inline constexpr area_density_t area_density{};
using area_density_r = make_refinement_symbol_t<area_density_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::area_density_t> { static constexpr char str[] = "kg/m^2"; };
}

#endif
