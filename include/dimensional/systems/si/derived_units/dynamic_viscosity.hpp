#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DYNAMIC_VISCOSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DYNAMIC_VISCOSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "pressure.hpp"

namespace mitama::systems::si {
template<class> struct dynamic_viscosity_synonym{};
using dynamic_viscosity_t = make_synonym_t<dynamic_viscosity_synonym, decltype(pascal * seconds)>;

inline constexpr dynamic_viscosity_t dynamic_viscosity{};
using dynamic_viscosity_r = make_refinement_symbol_t<dynamic_viscosity_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::dynamic_viscosity_t> { static constexpr char str[] = "Pa·s"; };
}
#endif
