#ifndef MITAMA_DIMENSIONAL_SI_UNITS_MOL_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_MOL_HPP
#include "../quantity.hpp"

namespace mitama::si {
// base dimesnion
struct amount_of_substance {
    using is_base_dimension = void;
};

using mol_t = make_unit_t<amount_of_substance>;
using millimol_t = scaled_unit_t<mol_t, std::milli>;
using micromol_t = scaled_unit_t<mol_t, std::micro>;
using kilomol_t = scaled_unit_t<mol_t, std::kilo>;

inline constexpr mol_t mols{};
inline constexpr millimol_t millimols{};
inline constexpr micromol_t micromols{};
inline constexpr kilomol_t kilomols{};

template < std::intmax_t N = 1 > inline constexpr powered_t<mol_t, N> mol{};
template < std::intmax_t N = 1 > inline constexpr powered_t<millimol_t, N> millimol{};
template < std::intmax_t N = 1 > inline constexpr powered_t<micromol_t, N> micromol{};
template < std::intmax_t N = 1 > inline constexpr powered_t<kilomol_t, N> kilomol{};

}

#endif