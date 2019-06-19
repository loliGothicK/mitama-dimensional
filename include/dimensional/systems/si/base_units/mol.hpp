#ifndef MITAMA_DIMENSIONAL_SI_UNITS_MOL_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_MOL_HPP
#include <dimensional/systems/si/base_dimension/amount_of_substance.hpp>
#include <dimensional/systems/si/prefix.hpp>
#include <dimensional/units.hpp>

namespace mitama::systems::si {
using mole_base_unit = base_units<amount_of_substance, 0>;
using mol_t = typename mole_base_unit::unit_type;
using millimol_t = scaled_unit_t<mol_t, std::milli>;
using micromol_t = scaled_unit_t<mol_t, std::micro>;
using kilomol_t = scaled_unit_t<mol_t, std::kilo>;

template < std::intmax_t N = 1 > using mol_ = powered_t<mol_t, N>;
template < std::intmax_t N = 1 > using millimol_ = powered_t<millimol_t, N>;
template < std::intmax_t N = 1 > using micromol_ = powered_t<micromol_t, N>;
template < std::intmax_t N = 1 > using kilomol_ = powered_t<kilomol_t, N>;


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
