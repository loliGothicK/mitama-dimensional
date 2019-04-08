#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_FIELD_STRENGTH_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_FIELD_STRENGTH_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "voltage.hpp"

namespace mitama::si {
template<class> struct electric_field_strength_repr{};
using electric_field_strength_t = make_synonym_t<electric_field_strength_repr, decltype(volts / meters)>;

inline constexpr electric_field_strength_t electric_field_strength{};
}

namespace mitama {
template <> struct abbreviation<si::electric_field_strength_t> { static constexpr char str[] = "V/m"; };
}
#endif
