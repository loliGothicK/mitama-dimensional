#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SURFACE_TENSION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SURFACE_TENSION_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "force.hpp"

namespace mitama::systems::si {
template<class> struct surface_tension_synonym{};
using surface_tension_t = make_synonym_t<surface_tension_synonym, decltype(newton / meter<>)>;

inline constexpr surface_tension_t surface_tension{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::surface_tension_t> { static constexpr char str[] = "N/m"; };
}

#endif
