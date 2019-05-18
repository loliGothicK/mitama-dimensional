#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CONDUCTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CONDUCTANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct conductance_synonym{};
using conductance_t = make_synonym_t<conductance_synonym, decltype(kilogram<-1> * meter<-2> * second<3> * ampere<2>)>;

inline constexpr conductance_t siemens{};
using conductance_r = make_refinement_symbol_t<conductance_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::conductance_t> { static constexpr char str[] = "S"; };
}
#endif
