#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_MASS_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_MASS_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using molar_mass_t = decltype(kilogram<> / mol<>);

inline constexpr molar_mass_t molar_mass{};
}

namespace mitama {
template <> struct abbreviation<si::molar_mass_t> { static constexpr char str[] = "kg/mol"; };
}
#endif
