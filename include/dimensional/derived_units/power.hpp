#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POWER_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct power_repr{};
using power_t = make_synonym_t<power_repr, decltype(kilogram<> * meter<2> * second<-3>)>;

inline constexpr power_t watt{};
}

namespace mitama {
template <> struct abbreviation<si::power_t> { static constexpr char str[] = "W"; };
}

#endif
