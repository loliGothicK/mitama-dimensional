#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FIELD_STRENGTH_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FIELD_STRENGTH_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct magnetic_field_strength_repr{};
using magnetic_field_strength_t = make_synonym_t<magnetic_field_strength_repr, decltype(ampere<> / meter<>)>;

inline constexpr magnetic_field_strength_t magnetic_field_strength{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
namespace mitama {
template <> struct abbreviation<si::magnetic_field_strength_t> { static constexpr char str[] = "A/m"; };
}
#endif

#endif
