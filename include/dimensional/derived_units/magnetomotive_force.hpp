#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETOMOTIVE_FORCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETOMOTIVE_FORCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "angle.hpp"

namespace mitama::si {
template<class> struct magnetomotive_force_synonym{};
using magnetomotive_force_t = make_synonym_t<magnetomotive_force_synonym, decltype(ampere<> * radian)>;

inline constexpr magnetomotive_force_t magnetomotive_force{};
using magnetomotive_force_r = make_refinement_symbol_t<magnetomotive_force_t>;
}

namespace mitama {
template <> struct abbreviation<si::magnetomotive_force_t> { static constexpr char str[] = "A·rad"; };
}

#endif
