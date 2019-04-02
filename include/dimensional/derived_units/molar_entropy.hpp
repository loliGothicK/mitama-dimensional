#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENTROPY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENTROPY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "energy.hpp"

namespace mitama::si {
using molar_entropy_t = decltype( joule / (kelvin<> * mol<>) );

inline constexpr molar_entropy_t molar_entropy{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_HEAT_CAPACITY_HPP
namespace mitama {
template <> struct abbreviation<si::molar_entropy_t> { static constexpr char str[] = "J/(K·mol)"; };
}
#endif

#endif
