#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_INTENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECTRAL_INTENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"
#include "solid_angle.hpp"

namespace mitama::si {
template<class> struct spectral_intensity_repr{};
using spectral_intensity_t = make_synonym_t<spectral_intensity_repr, decltype( watt / steradian * meter<-1> )>;

inline constexpr spectral_intensity_t spectral_intensity{};
}

namespace mitama {
template <> struct abbreviation<si::spectral_intensity_t> { static constexpr char str[] = "W/(sr·m)"; };
}
#endif
