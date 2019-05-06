#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct magnetization_repr{};
using magnetization_t = make_synonym_t<magnetization_repr, decltype(ampere<> / meter<>)>;

inline constexpr magnetization_t magnetization{};
using magnetization_r = make_refinement_symbol_t<magnetization_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FIELD_STRENGTH_HPP
namespace mitama {
template <> struct abbreviation<si::magnetization_t> { static constexpr char str[] = "A/m"; };
}
#endif

#endif
