#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_COMPRESSIBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_COMPRESSIBILITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct compressibility_synonym{};
using compressibility_t = make_synonym_t<compressibility_synonym, decltype(meter<> * kilogram<-1> * second<2>)>;

inline constexpr compressibility_t compressibility{};
using compressibility_r = make_refinement_symbol_t<compressibility_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::compressibility_t> { static constexpr char str[] = "Pa^-1"; };
}
#endif
