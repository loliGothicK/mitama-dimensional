#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "./power.hpp"

namespace mitama::systems::si {
template<class> struct heat_flux_synonym{};
using heat_flux_t = make_synonym_t<heat_flux_synonym, decltype(watt * meter<-2>)>;

inline constexpr heat_flux_t heat_flux{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::heat_flux_t> { static constexpr char str[] = "W/m^2"; };
}
#endif
