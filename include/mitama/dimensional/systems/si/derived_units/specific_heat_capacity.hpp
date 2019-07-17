#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_HEAT_CAPACITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_HEAT_CAPACITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>
#include "energy.hpp"


namespace mitama::systems::si {
template<class> struct specific_heat_capacity_synonym{};
using specific_heat_capacity_t = make_synonym_t<specific_heat_capacity_synonym, decltype( joule * kilogram<-1> * kelvin<-1> )>;

inline constexpr specific_heat_capacity_t specific_heat_capacity{};
using specific_heat_capacity_r = make_refinement_symbol_t<specific_heat_capacity_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENTROPY_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::specific_heat_capacity_t> { static constexpr char str[] = "J/(K kg)"; };
}
#endif

#endif
