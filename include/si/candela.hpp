#pragma once
#include "../units.hpp"

namespace mitama {
struct luminous_intensity {};

using candela_t = make_unit_t<luminous_intensity>;

inline constexpr candela_t candelas{};

template < std::intmax_t N > inline constexpr powered_t<candela_t, N> candela{};

}