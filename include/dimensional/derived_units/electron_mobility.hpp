#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRON_MOBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRON_MOBILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "voltage.hpp"

namespace mitama::si {
template<class> struct electron_mobility_synonym{};
using electron_mobility_t = make_synonym_t<electron_mobility_synonym, decltype( meter<2> * volt<-1> * second<-1> )>;

inline constexpr electron_mobility_t electron_mobility{};
using electron_mobility_r = make_refinement_symbol_t<electron_mobility_t>;
}

namespace mitama {
template <> struct abbreviation<si::electron_mobility_t> { static constexpr char str[] = "m^2/(V·s)"; };
}
#endif
