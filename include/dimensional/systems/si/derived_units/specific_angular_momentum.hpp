#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ANGULAR_MOMENTUM_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ANGULAR_MOMENTUM_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct specific_angular_momentum_synonym{};
using specific_angular_momentum_t = make_synonym_t<specific_angular_momentum_synonym, decltype(meter<2> * second<-1>)>;

inline constexpr specific_angular_momentum_t specific_angular_momentum{};
using specific_angular_momentum_r = make_refinement_symbol_t<specific_angular_momentum_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::specific_angular_momentum_t> { static constexpr char str[] = "N m s/kg"; };
}
#endif
