#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENTUM_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENTUM_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using momentum_t = decltype(meter<> * kilogram<> * second<-1>);

inline constexpr momentum_t momentum{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPULSE_HPP
namespace mitama {
template <> struct abbreviation<si::momentum_t> { static constexpr char str[] = "N·s"; };
}
#endif

#endif