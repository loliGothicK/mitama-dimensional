#pragma once
#include "../units.hpp"

namespace mitama {
// base dimension
struct thermodynamic_temperature {};

using kelvin_t = make_unit_t<thermodynamic_temperature>;

inline constexpr kelvin_t kelvins{};

template < std::intmax_t N > inline constexpr powered_t<kelvin_t, N> kelvin{};

}