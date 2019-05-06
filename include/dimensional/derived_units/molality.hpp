#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLALITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLALITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct molality_repr{};
using molality_t = make_synonym_t<molality_repr, decltype(mol<> / kilogram<>)>;

inline constexpr molality_t molality{};
using molality_r = make_refinement_symbol_t<molality_t>;
}

namespace mitama {
template <> struct abbreviation<si::molality_t> { static constexpr char str[] = "mol/kg"; };
}
#endif
