#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct heat_flux_repr{};
using heat_flux_t = make_synonym_t<heat_flux_repr, decltype(watt * meter<-2>)>;

inline constexpr heat_flux_t heat_flux{};
}

namespace mitama {
template <> struct abbreviation<si::heat_flux_t> { static constexpr char str[] = "W/m^2"; };
}
#endif
