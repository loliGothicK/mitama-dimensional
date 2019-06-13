#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_EFFICIENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_EFFICIENCY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct catalytic_efficiency_synonym{};
using catalytic_efficiency_t = make_synonym_t<catalytic_efficiency_synonym, decltype(meter<3> / (mol<> * second<>))>;

inline constexpr catalytic_efficiency_t catalytic_efficiency{};
using catalytic_efficiency_r = make_refinement_symbol_t<catalytic_efficiency_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::catalytic_efficiency_t> { static constexpr char str[] = "m^3/(mol s)"; };
}
#endif
