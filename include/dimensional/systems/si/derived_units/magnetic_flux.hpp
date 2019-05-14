#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FLUX_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
template<class> struct magnetic_flux_synonym{};
using magnetic_flux_t = make_synonym_t<magnetic_flux_synonym, decltype(kilogram<> * meter<2> * second<-2> * ampere<-1>)>;

inline constexpr magnetic_flux_t weber{};
using magnetic_flux_r = make_refinement_symbol_t<magnetic_flux_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::magnetic_flux_t> { static constexpr char str[] = "Wb"; };
}
#endif
