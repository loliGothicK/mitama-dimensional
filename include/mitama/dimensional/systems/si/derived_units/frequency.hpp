#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>

namespace mitama::systems::si {
using frequency_t = reciprocal_t<second_t>;
inline constexpr frequency_t hertz{};
using frequency_r = make_refinement_symbol_t<frequency_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::frequency_t> { static constexpr char str[] = "Hz"; };
}
#endif