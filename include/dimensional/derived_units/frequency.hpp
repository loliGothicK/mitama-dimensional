#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"

namespace mitama::si {
using frequency_t = reciprocal_t<second_t>;
inline constexpr frequency_t hertz{};
using frequency_r = make_refiment_symbol_t<frequency_t>;
}

namespace mitama {
template <> struct abbreviation<si::frequency_t> { static constexpr char str[] = "Hz"; };
}
#endif