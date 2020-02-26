#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_AREA_DENSITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct area_density_synonym{};
using area_density_t = make_synonym_t<area_density_synonym, decltype(meter<-2> * kilogram<>)>;

inline constexpr area_density_t area_density{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::area_density_t> { static constexpr char str[] = "kg/m^2"; };
}

#endif
