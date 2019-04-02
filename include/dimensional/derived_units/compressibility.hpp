#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_COMPRESSIBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_COMPRESSIBILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using compressibility_t = decltype(meter<> * kilogram<-1> * second<2>);

inline constexpr compressibility_t compressibility{};
}

namespace mitama {
template <> struct abbreviation<si::compressibility_t> { static constexpr char str[] = "Pa^-1"; };
}
#endif
