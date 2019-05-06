#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FLUX_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FLUX_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct magnetic_flux_density_synonym{};
using magnetic_flux_density_t = make_synonym_t<magnetic_flux_density_synonym, decltype(kilogram<> * second<-2> * ampere<-1>)>;

inline constexpr magnetic_flux_density_t tesla{};
using magnetic_flux_density_r = make_refinement_symbol_t<magnetic_flux_density_t>;
}

namespace mitama {
template <> struct abbreviation<si::magnetic_flux_density_t> { static constexpr char str[] = "T"; };
}
#endif
