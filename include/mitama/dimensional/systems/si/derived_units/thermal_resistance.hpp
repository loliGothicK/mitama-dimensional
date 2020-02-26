#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_RESISTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_RESISTANCE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "power.hpp"


namespace mitama::systems::si {
template<class> struct thermal_resistance_synonym{};
using thermal_resistance_t = make_synonym_t<thermal_resistance_synonym, decltype(kelvin<> / watt)>;

inline constexpr thermal_resistance_t thermal_resistance{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::thermal_resistance_t> { static constexpr char str[] = "K/W"; };
}
#endif
