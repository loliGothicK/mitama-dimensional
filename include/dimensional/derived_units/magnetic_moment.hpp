#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_MOMENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_MOMENT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "magnetic_flux.hpp"

namespace mitama::si {
using magnetic_moment_t = decltype(weber * meter<>);

inline constexpr magnetic_moment_t magnetic_moment{};
}

namespace mitama {
template <> struct abbreviation<si::magnetic_moment_t> { static constexpr char str[] = "Wb·m"; };
}
#endif
