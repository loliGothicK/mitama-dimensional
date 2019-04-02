#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENT_OF_INERTIA_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOMENT_OF_INERTIA_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using moment_of_inertia_t = decltype(kilogram<> * meter<2>);

inline constexpr moment_of_inertia_t moment_of_inertia{};
}

namespace mitama {
template <> struct abbreviation<si::moment_of_inertia_t> { static constexpr char str[] = "kg·m^2"; };
}

#endif
