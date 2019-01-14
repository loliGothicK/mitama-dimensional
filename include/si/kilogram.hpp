#pragma once
#include "../units.hpp"

namespace mitama {
// base dimension
struct mass {};

// base unit
using kilogram_t = make_unit_t<mass>;
using gram_t = scaled_unit_t<kilogram_t, std::milli>;


inline constexpr kilogram_t kilograms;
inline constexpr gram_t grams;

template < std::intmax_t N > inline constexpr powered_t<kilogram_t, N> kilogram{};
template < std::intmax_t N > inline constexpr powered_t<gram_t, N> gram{};

}