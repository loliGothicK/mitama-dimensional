#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_HEAT_CAPACITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_HEAT_CAPACITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "energy.hpp"


namespace mitama::si {
template<class> struct specific_heat_capacity_repr{};
using specific_heat_capacity_t = make_synonym_t<specific_heat_capacity_repr, decltype( joule * kilogram<-1> * kelvin<-1> )>;

inline constexpr specific_heat_capacity_t specific_heat_capacity{};
using specific_heat_capacity_r = make_refiment_symbol_t<specific_heat_capacity_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENTROPY_HPP
namespace mitama {
template <> struct abbreviation<si::specific_heat_capacity_t> { static constexpr char str[] = "J/(K·kg)"; };
}
#endif

#endif
