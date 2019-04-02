#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPULSE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_IMPULSE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using impulse_t = decltype(meter<> * kilogram<> * second<-1>);

inline constexpr impulse_t impulse{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENTUM_HPP
namespace mitama {
template <> struct abbreviation<si::impulse_t> { static constexpr char str[] = "N·s"; };
}
#endif

#endif
