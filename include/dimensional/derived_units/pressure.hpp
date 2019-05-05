#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PASCAL_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PASCAL_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"

namespace mitama::si {
template<class> struct pressure_repr{};
using pressure_t = make_synonym_t<pressure_repr, decltype(kilogram<> * meter<-1> * second<-2>)>;
inline constexpr pressure_t pascal{};
using pressure_r = make_refinement_symbol_t<pressure_t>;
}

namespace mitama {
template <> struct abbreviation<si::pressure_t> { static constexpr char str[] = "Pa"; };
}
#endif