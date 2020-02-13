#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_CHARGE_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LINEAR_CHARGE_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "electric_charge.hpp"

namespace mitama::systems::si {
template<class> struct linear_charge_density_synonym{};
using linear_charge_density_t = make_synonym_t<linear_charge_density_synonym, decltype(coulomb / meter<>)>;

inline constexpr linear_charge_density_t linear_charge_density{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::linear_charge_density_t> { static constexpr char str[] = "C/m"; };
}
#endif
