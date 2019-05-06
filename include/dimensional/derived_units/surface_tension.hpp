#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SURFACE_TENSION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SURFACE_TENSION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "force.hpp"

namespace mitama::si {
template<class> struct surface_tension_synonym{};
using surface_tension_t = make_synonym_t<surface_tension_synonym, decltype(newton / meter<>)>;

inline constexpr surface_tension_t surface_tension{};
using surface_tension_r = make_refinement_symbol_t<surface_tension_t>;
}

namespace mitama {
template <> struct abbreviation<si::surface_tension_t> { static constexpr char str[] = "N/m"; };
}

#endif
