#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MASS_FLOW_RATE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MASS_FLOW_RATE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct mass_flow_rate_synonym{};
using mass_flow_rate_t = make_synonym_t<mass_flow_rate_synonym, decltype(kilogram<> / second<>)>;

inline constexpr mass_flow_rate_t mass_flow_rate{};
using mass_flow_rate_r = make_refinement_symbol_t<mass_flow_rate_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::mass_flow_rate_t> { static constexpr char str[] = "kg/s"; };
}

#endif
