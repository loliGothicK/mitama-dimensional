#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_INTENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_INTENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "power.hpp"
#include "solid_angle.hpp"

namespace mitama::systems::si {
template<class> struct radiant_intensity_synonym{};
using radiant_intensity_t = make_synonym_t<radiant_intensity_synonym, decltype(watt / steradian)>;

inline constexpr radiant_intensity_t radiant_intensity{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::radiant_intensity_t> { static constexpr char str[] = "W/sr"; };
}
#endif
