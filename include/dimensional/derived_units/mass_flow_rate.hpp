#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MASS_FLOW_RATE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MASS_FLOW_RATE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct mass_flow_rate_repr{};
using mass_flow_rate_t = make_synonym_t<mass_flow_rate_repr, decltype(kilogram<> / second<>)>;

inline constexpr mass_flow_rate_t mass_flow_rate{};
using mass_flow_rate_r = make_refiment_symbol_t<mass_flow_rate_t>;
}

namespace mitama {
template <> struct abbreviation<si::mass_flow_rate_t> { static constexpr char str[] = "kg/s"; };
}

#endif
