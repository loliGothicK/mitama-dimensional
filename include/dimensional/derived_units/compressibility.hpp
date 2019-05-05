#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_COMPRESSIBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_COMPRESSIBILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct compressibility_repr{};
using compressibility_t = make_synonym_t<compressibility_repr, decltype(meter<> * kilogram<-1> * second<2>)>;

inline constexpr compressibility_t compressibility{};
using compressibility_r = make_refinement_symbol_t<compressibility_t>;
}

namespace mitama {
template <> struct abbreviation<si::compressibility_t> { static constexpr char str[] = "Pa^-1"; };
}
#endif
