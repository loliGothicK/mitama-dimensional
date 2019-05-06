#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ANGULAR_MOMENTUM_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ANGULAR_MOMENTUM_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct specific_angular_momentum_repr{};
using specific_angular_momentum_t = make_synonym_t<specific_angular_momentum_repr, decltype(meter<2> * second<-1>)>;

inline constexpr specific_angular_momentum_t specific_angular_momentum{};
using specific_angular_momentum_r = make_refinement_symbol_t<specific_angular_momentum_t>;
}

namespace mitama {
template <> struct abbreviation<si::specific_angular_momentum_t> { static constexpr char str[] = "N·m·s/kg"; };
}
#endif
