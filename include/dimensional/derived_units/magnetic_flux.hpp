#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FLUX_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::si {
template<class> struct magnetic_flux_repr{};
using magnetic_flux_t = make_synonym_t<magnetic_flux_repr, decltype(kilogram<> * meter<2> * second<-2> * ampere<-1>)>;

inline constexpr magnetic_flux_t weber{}; 
}

namespace mitama {
template <> struct abbreviation<si::magnetic_flux_t> { static constexpr char str[] = "Wb"; };
}
#endif
