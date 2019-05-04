#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "electric_charge.hpp"

namespace mitama::si {
template<class> struct electric_charge_density_repr{};
using electric_charge_density_t = make_synonym_t<electric_charge_density_repr, decltype(coulomb / meter<3>)>;

inline constexpr electric_charge_density_t electric_charge_density{};
using electric_charge_density_r = make_refiment_symbol_t<electric_charge_density_t>;
inline constexpr electric_charge_density_t charge_density{};
using electric_charge_density_r = make_refiment_symbol_t<electric_charge_density_t>;
}

namespace mitama {
template <> struct abbreviation<si::electric_charge_density_t> { static constexpr char str[] = "C/m^3"; };
}
#endif
