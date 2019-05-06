#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_HEAT_CAPACITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_HEAT_CAPACITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "energy.hpp"

namespace mitama::si {
template<class> struct molar_heat_capacity_repr{};
using molar_heat_capacity_t = make_synonym_t<molar_heat_capacity_repr, decltype( joule / (kelvin<> * mol<>) )>;

inline constexpr molar_heat_capacity_t molar_heat_capacity{};
using molar_heat_capacity_r = make_refinement_symbol_t<molar_heat_capacity_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENTROPY_HPP
namespace mitama {
template <> struct abbreviation<si::molar_heat_capacity_t> { static constexpr char str[] = "J/(K·mol)"; };
}
#endif

#endif
