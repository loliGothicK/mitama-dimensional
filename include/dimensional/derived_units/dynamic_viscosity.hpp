#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DYNAMIC_VISCOSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DYNAMIC_VISCOSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "pressure.hpp"

namespace mitama::si {
using dynamic_viscosity_t = decltype(pascal * seconds);

inline constexpr dynamic_viscosity_t dynamic_viscosity{};
}

namespace mitama {
template <> struct abbreviation<si::dynamic_viscosity_t> { static constexpr char str[] = "Pa·s"; };
}
#endif
