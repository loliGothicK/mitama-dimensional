#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_EFFICIENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_EFFICIENCY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct catalytic_efficiency_synonym{};
using catalytic_efficiency_t = make_synonym_t<catalytic_efficiency_synonym, decltype(meter<3> / (mol<> * second<>))>;

inline constexpr catalytic_efficiency_t catalytic_efficiency{};
using catalytic_efficiency_r = make_refinement_symbol_t<catalytic_efficiency_t>;
}

namespace mitama {
template <> struct abbreviation<si::catalytic_efficiency_t> { static constexpr char str[] = "m^3/(mol·s)"; };
}
#endif
