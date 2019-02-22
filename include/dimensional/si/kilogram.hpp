#pragma once
#include "../units.hpp"
#include "../quotient.hpp"

namespace mitama {
// base dimension
struct mass {
    using is_base_dimension = void;
};

// base unit
using kilogram_t = make_unit_t<mass>;
using gram_t = scaled_unit_t<kilogram_t, std::milli>;


inline constexpr kilogram_t kilograms;
inline constexpr gram_t grams;

template < std::intmax_t N = 1> inline constexpr powered_t<kilogram_t, N> kilogram{};
template < std::intmax_t N = 1> inline constexpr powered_t<gram_t, N> gram{};

}