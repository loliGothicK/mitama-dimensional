#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"
#include "solid_angle.hpp"

namespace mitama::si {
template<class> struct radiance_repr{};
using radiance_t = make_synonym_t<radiance_repr, decltype( watt / steradian * meter<-2> )>;

inline constexpr radiance_t radiance{};
}

namespace mitama {
template <> struct abbreviation<si::radiance_t> { static constexpr char str[] = "W/(sr·m^2)"; };
}
#endif
