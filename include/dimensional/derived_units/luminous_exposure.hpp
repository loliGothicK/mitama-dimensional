#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EXPOSURE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_EXPOSURE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "solid_angle.hpp"

namespace mitama::si {
template<class> struct luminous_exposure_repr{};
using luminous_exposure_t = make_synonym_t<luminous_exposure_repr, decltype(meter<-2>*seconds*candelas*steradian)>;

inline constexpr luminous_exposure_t luminous_exposure{};
using luminous_exposure_r = make_refinement_symbol_t<luminous_exposure_t>;
}

namespace mitama {
template <> struct abbreviation<si::luminous_exposure_t> { static constexpr char str[] = "lx·s"; };
}
#endif
