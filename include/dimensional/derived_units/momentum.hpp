#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENTUM_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENTUM_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct momentum_repr{};
using momentum_t = make_synonym_t<momentum_repr, decltype(meter<> * kilogram<> * second<-1>)>;

inline constexpr momentum_t momentum{};
using momentum_r = make_refinement_symbol_t<momentum_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPULSE_HPP
namespace mitama {
template <> struct abbreviation<si::momentum_t> { static constexpr char str[] = "N·s"; };
}
#endif

#endif
