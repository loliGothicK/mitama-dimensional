#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_DIPOLE_MOMENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_DIPOLE_MOMENT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "energy.hpp"
#include "magnetic_flux_density.hpp"

namespace mitama::si {
template<class> struct magnetic_dipole_moment_repr{};
using magnetic_dipole_moment_t = make_synonym_t<magnetic_dipole_moment_repr, decltype(joule / tesla)>;

inline constexpr magnetic_dipole_moment_t magnetic_dipole_moment{};
using magnetic_dipole_moment_r = make_refinement_symbol_t<magnetic_dipole_moment_t>;
}

namespace mitama {
template <> struct abbreviation<si::magnetic_dipole_moment_t> { static constexpr char str[] = "J/T"; };
}
#endif
