#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FREQUENCY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>


namespace mitama::systems::si {
using frequency_t = reciprocal_t<second_t>;
inline constexpr frequency_t hertz{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::frequency_t> { static constexpr char str[] = "Hz"; };
}
#endif