#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_INTENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANT_INTENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "power.hpp"
#include "solid_angle.hpp"

namespace mitama::systems::si {
template<class> struct radiant_intensity_synonym{};
using radiant_intensity_t = make_synonym_t<radiant_intensity_synonym, decltype(watt / steradian)>;

inline constexpr radiant_intensity_t radiant_intensity{};
using radiant_intensity_r = make_refinement_symbol_t<radiant_intensity_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::radiant_intensity_t> { static constexpr char str[] = "W/sr"; };
}
#endif
