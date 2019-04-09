#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACCELERATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACCELERATION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct acceleration_repr{};
using acceleration_t = make_synonym_t<acceleration_repr, decltype(meters * second<-2>)>;

inline constexpr acceleration_t acceleration{};
}

namespace mitama {
template <> struct abbreviation<si::acceleration_t> { static constexpr char str[] = "m/s^2"; };
}

#endif
