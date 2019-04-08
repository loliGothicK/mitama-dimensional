#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct density_repr{};
using density_t = make_synonym_t<density_repr, decltype(meter<-3> * kilogram<>)>;

inline constexpr density_t density{};
}

namespace mitama {
template <> struct abbreviation<si::density_t> { static constexpr char str[] = "kg/m^3"; };
}


#endif
