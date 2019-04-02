#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_RIGIDITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_RIGIDITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "magnetic_flux_density.hpp"

namespace mitama::si {
using magnetic_rigidity_t = decltype(tesla * meter<>);

inline constexpr magnetic_rigidity_t magnetic_rigidity{};
}

namespace mitama {
template <> struct abbreviation<si::magnetic_rigidity_t> { static constexpr char str[] = "T·m"; };
}
#endif
