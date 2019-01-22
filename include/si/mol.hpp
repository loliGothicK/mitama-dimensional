#pragma once
#include "../units.hpp"

namespace mitama {
// base dimesnion
struct amount_of_substance {};

using mol_t = make_unit_t<amount_of_substance>;

inline constexpr mol_t mols{};

template < std::intmax_t N = 1 > inline constexpr powered_t<mol_t, N> mol{};

}