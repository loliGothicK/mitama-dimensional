#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DYNAMIC_VISCOSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DYNAMIC_VISCOSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "pressure.hpp"

namespace mitama::si {
template<class> struct dynamic_viscosity_synonym{};
using dynamic_viscosity_t = make_synonym_t<dynamic_viscosity_synonym, decltype(pascal * seconds)>;

inline constexpr dynamic_viscosity_t dynamic_viscosity{};
using dynamic_viscosity_r = make_refinement_symbol_t<dynamic_viscosity_t>;
}

namespace mitama {
template <> struct abbreviation<si::dynamic_viscosity_t> { static constexpr char str[] = "Pa·s"; };
}
#endif
