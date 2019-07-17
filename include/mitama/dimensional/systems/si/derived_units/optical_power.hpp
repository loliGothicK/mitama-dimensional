#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_OPTICAL_POWER_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_OPTICAL_POWER_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>


namespace mitama::systems::si {
using optical_power_t = reciprocal_t<meter_t>;

inline constexpr optical_power_t optical_power{};
using optical_power_r = make_refinement_symbol_t<optical_power_t>;
}

#endif
