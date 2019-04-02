#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_VECTOR_POTENTIAL_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_VECTOR_POTENTIAL_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "magnetic_flux.hpp"

namespace mitama::si {
using magnetic_vector_potential_t = decltype(weber / meter<>);

inline constexpr magnetic_vector_potential_t magnetic_vector_potential{};
}

namespace mitama {
template <> struct abbreviation<si::magnetic_vector_potential_t> { static constexpr char str[] = "Wb/m"; };
}
#endif
