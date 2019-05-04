#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_TEMPERATURE_GRADIENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_TEMPERATURE_GRADIENT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct temperature_gradient_repr{};
using temperature_gradient_t = make_synonym_t<temperature_gradient_repr, decltype(kelvin<> / meter<>)>;

inline constexpr temperature_gradient_t temperature_gradient{};
using temperature_gradient_r = make_refiment_symbol_t<temperature_gradient_t>;
}

namespace mitama {
template <> struct abbreviation<si::temperature_gradient_t> { static constexpr char str[] = "K/m"; };
}

#endif
