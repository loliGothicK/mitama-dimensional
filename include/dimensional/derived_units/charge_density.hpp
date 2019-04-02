#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CHARGE_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CHARGE_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using electric_charge_density_t = decltype(coulomb / meter<3>);

inline constexpr electric_charge_density_t electric_charge_density{};
}

using charge_density_t = decltype(coulomb / meter<3>);

inline constexpr electric_charge_density_t charge_density{};
}

using linear_charge_density_t = decltype(coulomb / meter<>);

inline constexpr linear_charge_density_t linear_charge_density{};
}

namespace mitama {
template <> struct abbreviation<si::linear_charge_density_t> { static constexpr char str[] = "C/m"; };
}
namespace mitama {
template <> struct abbreviation<si::electric_charge_density_t> { static constexpr char str[] = "C/m^3"; };
}
#endif
