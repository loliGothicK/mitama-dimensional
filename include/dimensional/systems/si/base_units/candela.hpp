#ifndef MITAMA_DIMENSIONAL_SI_UNITS_CANDELA_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_CANDELA_HPP
#include <dimensional/systems/si/base_dimension/luminous_intensity.hpp>
#include <dimensional/systems/si/prefix.hpp>
#include <dimensional/units.hpp>

namespace mitama::systems::si {

using candela_base_unit = base_units<luminous_intensity, 0>;

using candela_t = typename candela_base_unit::unit_type;

template < std::intmax_t N = 1 >
using candela_ = powered_t<candela_t, N>;

inline constexpr candela_t candelas{};

template < std::intmax_t N = 1 > inline constexpr powered_t<candela_t, N> candela{};

}

#endif
