#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_INDUCTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_INDUCTANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct inductance_synonym{};
using inductance_t = make_synonym_t<inductance_synonym, decltype(kilogram<> * meter<2> * second<-2> * ampere<-2>)>;

inline constexpr inductance_t henry{};
using inductance_r = make_refinement_symbol_t<inductance_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::inductance_t> { static constexpr char str[] = "H"; };
}
#endif
