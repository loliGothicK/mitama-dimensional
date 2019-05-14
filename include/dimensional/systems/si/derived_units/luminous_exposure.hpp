#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EXPOSURE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EXPOSURE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "solid_angle.hpp"

namespace mitama::systems::si {
template<class> struct luminous_exposure_synonym{};
using luminous_exposure_t = make_synonym_t<luminous_exposure_synonym, decltype(meter<-2>*seconds*candela<>*steradian)>;

inline constexpr luminous_exposure_t luminous_exposure{};
using luminous_exposure_r = make_refinement_symbol_t<luminous_exposure_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::luminous_exposure_t> { static constexpr char str[] = "lx·s"; };
}
#endif
