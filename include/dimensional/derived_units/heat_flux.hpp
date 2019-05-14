#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "./power.hpp"

namespace mitama::si {
template<class> struct heat_flux_synonym{};
using heat_flux_t = make_synonym_t<heat_flux_synonym, decltype(watt * meter<-2>)>;

inline constexpr heat_flux_t heat_flux{};
using heat_flux_r = make_refinement_symbol_t<heat_flux_t>;
}

namespace mitama {
template <> struct abbreviation<si::heat_flux_t> { static constexpr char str[] = "W/m^2"; };
}
#endif