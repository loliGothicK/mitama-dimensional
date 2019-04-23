#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CHARGE_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CHARGE_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct electric_charge_density_repr{};
using electric_charge_density_t = make_synonym_t<electric_charge_density_repr, decltype(coulomb / meter<3>)>;

inline constexpr electric_charge_density_t electric_charge_density{};
using electric_charge_density_r = make_refiment_symbol_t<electric_charge_density_t>;
}

template<class> struct charge_density_repr{};
using charge_density_t = make_synonym_t<charge_density_repr, decltype(coulomb / meter<3>)>;

inline constexpr electric_charge_density_t charge_density{};
using electric_charge_density_r = make_refiment_symbol_t<electric_charge_density_t>;
}

template<class> struct linear_charge_density_repr{};
using linear_charge_density_t = make_synonym_t<linear_charge_density_repr, decltype(coulomb / meter<>)>;

inline constexpr linear_charge_density_t linear_charge_density{};
using linear_charge_density_r = make_refiment_symbol_t<linear_charge_density_t>;
}

namespace mitama {
template <> struct abbreviation<si::linear_charge_density_t> { static constexpr char str[] = "C/m"; };
}
namespace mitama {
template <> struct abbreviation<si::electric_charge_density_t> { static constexpr char str[] = "C/m^3"; };
}
#endif
