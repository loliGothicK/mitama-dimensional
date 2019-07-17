#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CURVATURE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CURVATURE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>


namespace mitama::systems::si {
using curvature_t = reciprocal_t<meter_t>;

inline constexpr curvature_t curvature{};
using curvature_r = make_refinement_symbol_t<curvature_t>;
}

#endif
