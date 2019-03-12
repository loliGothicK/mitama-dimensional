#pragma once
#include "../units.hpp"
#include "../quotient.hpp"

namespace mitama {
// base dimension
struct thermodynamic_temperature {
    using is_base_dimension = void;
};

using kelvin_t = make_unit_t<thermodynamic_temperature>;
using millikelvin_t = scaled_unit_t<kelvin_t, std::milli>;
using microkelvin_t = scaled_unit_t<kelvin_t, std::milli>;
using kilokelvin_t = scaled_unit_t<kelvin_t, std::kilo>;
using megakelvin_t = scaled_unit_t<kelvin_t, std::mega>;

inline constexpr kelvin_t kelvins{};

template < std::intmax_t N = 1 > inline constexpr powered_t<kelvin_t, N> kelvin{};

}