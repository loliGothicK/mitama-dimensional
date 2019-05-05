#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CURVATURE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CURVATURE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
using curvature_t = reciprocal_t<meter_t>;

inline constexpr curvature_t curvature{};
using curvature_r = make_refinement_symbol_t<curvature_t>;
}

#endif
