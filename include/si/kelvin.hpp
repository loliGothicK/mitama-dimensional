#pragma once
#include "../units.hpp"
#include "../quotient.hpp"

namespace mitama {
// base dimension
struct thermodynamic_temperature {};

using kelvin_t = make_unit_t<thermodynamic_temperature>;

inline constexpr kelvin_t kelvins{};

template < std::intmax_t N = 1 > inline constexpr powered_t<kelvin_t, N> kelvin{};

}