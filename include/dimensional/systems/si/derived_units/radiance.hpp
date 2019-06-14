#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RADIANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "power.hpp"
#include "solid_angle.hpp"

namespace mitama::systems::si {
template<class> struct radiance_synonym{};
using radiance_t = make_synonym_t<radiance_synonym, decltype( watt / steradian * meter<-2> )>;

inline constexpr radiance_t radiance{};
using radiance_r = make_refinement_symbol_t<radiance_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::radiance_t> { static constexpr char str[] = "W/(sr m^2)"; };
}
#endif
