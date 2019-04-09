#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_INTENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_INTENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "power.hpp"
#include "solid_angle.hpp"

namespace mitama::si {
template<class> struct radiant_intensity_repr{};
using radiant_intensity_t = make_synonym_t<radiant_intensity_repr, decltype(watt / steradian)>;

inline constexpr radiant_intensity_t radiant_intensity{};
}

namespace mitama {
template <> struct abbreviation<si::radiant_intensity_t> { static constexpr char str[] = "W/sr"; };
}
#endif
