#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_JERK_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_JERK_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct jerk_synonym{};
using jerk_t = make_synonym_t<jerk_synonym, decltype(meters * second<-3>)>;

inline constexpr jerk_t jerk{};
using jerk_r = make_refinement_symbol_t<jerk_t>;
}

namespace mitama {
template <> struct abbreviation<si::jerk_t> { static constexpr char str[] = "m/s^3"; };
}

#endif
