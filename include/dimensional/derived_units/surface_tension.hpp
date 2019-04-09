#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SURFACE_TENSION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SURFACE_TENSION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "force.hpp"

namespace mitama::si {
template<class> struct surface_tension_repr{};
using surface_tension_t = make_synonym_t<surface_tension_repr, decltype(newton / meter<>)>;

inline constexpr surface_tension_t surface_tension{};
}

namespace mitama {
template <> struct abbreviation<si::surface_tension_t> { static constexpr char str[] = "N/m"; };
}

#endif
