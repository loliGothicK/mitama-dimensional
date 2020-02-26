#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_DIPOLE_MOMENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_DIPOLE_MOMENT_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "energy.hpp"
#include "magnetic_flux_density.hpp"

namespace mitama::systems::si {
template<class> struct magnetic_dipole_moment_synonym{};
using magnetic_dipole_moment_t = make_synonym_t<magnetic_dipole_moment_synonym, decltype(joule / tesla)>;

inline constexpr magnetic_dipole_moment_t magnetic_dipole_moment{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::magnetic_dipole_moment_t> { static constexpr char str[] = "J/T"; };
}
#endif
