#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_CAPACITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_CAPACITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "energy.hpp"


namespace mitama::systems::si {
template<class> struct heat_capacity_synonym{};
using heat_capacity_t = make_synonym_t<heat_capacity_synonym, decltype(joule / kelvins)>;

inline constexpr heat_capacity_t heat_capacity{};

}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENTROPY_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::heat_capacity_t> { static constexpr char str[] = "J/K"; };
}
#endif

#endif
