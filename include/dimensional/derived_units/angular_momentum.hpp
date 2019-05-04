#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_MOMENTUM_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ANGULAR_MOMENTUM_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"

namespace mitama::si {
template<class> struct angular_momentum_repr{};
using angular_momentum_t = make_synonym_t<angular_momentum_repr, decltype(meter<2> * kilogram<> * second<-1>)>;

inline constexpr angular_momentum_t angular_momentum{};
using angular_momentum_r = make_refiment_symbol_t<angular_momentum_t>;
}

namespace mitama {
template <> struct abbreviation<si::angular_momentum_t> { static constexpr char str[] = "N·m·s"; };
}
#endif
