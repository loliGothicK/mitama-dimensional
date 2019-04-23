#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_CHARGE_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_CHARGE_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "electric_charge.hpp"

namespace mitama::si {
template<class> struct linear_charge_density_repr{};
using linear_charge_density_t = make_synonym_t<linear_charge_density_repr, decltype(coulomb / meter<>)>;

inline constexpr linear_charge_density_t linear_charge_density{};
using linear_charge_density_r = make_refiment_symbol_t<linear_charge_density_t>;
}

namespace mitama {
template <> struct abbreviation<si::linear_charge_density_t> { static constexpr char str[] = "C/m"; };
}
#endif
