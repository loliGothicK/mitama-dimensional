#ifndef MITAMA_DIMENSIONAL_SI_UNITS_CANDELA_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_CANDELA_HPP
#include <dimensional/systems/si/base_units/fwd/si_base_units.hpp>
#include <dimensional/systems/si/prefix.hpp>
#include <dimensional/units.hpp>

namespace mitama::systems::si {

using candela_t = typename candela_base_unit::unit_type_with_system<::mitama::systems::si::system>;
using millicandela_t = scaled_unit_t<candela_t, std::milli>;

template < std::intmax_t N = 1 >
using candela_ = powered_t<candela_t, N>;

inline constexpr candela_t candelas{};
inline constexpr millicandela_t millicandelas{};

template < std::intmax_t N = 1 > inline constexpr powered_t<candela_t, N> candela{};

}

#endif
