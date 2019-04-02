#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::si {
using frequency_t = reciprocal_t<second_t>;
inline constexpr frequency_t hertz{}; 
}

namespace mitama {
template <> struct abbreviation<si::frequency_t> { static constexpr char str[] = "Hz"; };
}
#endif