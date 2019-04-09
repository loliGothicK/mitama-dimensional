#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct luminance_repr{};
using luminance_t = make_synonym_t<luminance_repr, decltype(candela<> * meter<-2>)>;

inline constexpr luminance_t luminance{};
}

namespace mitama {
template <> struct abbreviation<si::luminance_t> { static constexpr char str[] = "cd/m^2"; };
}
#endif
