#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FLUX_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FLUX_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using magnetic_flux_density_t = decltype(kilogram<> * second<-2> * ampere<-1>);

inline constexpr magnetic_flux_density_t tesla{}; 
}

namespace mitama {
template <> struct abbreviation<si::magnetic_flux_density_t> { static constexpr char str[] = "T"; };
}
#endif
