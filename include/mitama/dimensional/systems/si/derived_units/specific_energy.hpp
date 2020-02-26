#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_SPECIFIC_ENERGY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct specific_energy_synonym{};
using specific_energy_t = make_synonym_t<specific_energy_synonym, decltype(joule / kilogram<>)>;

inline constexpr specific_energy_t specific_energy{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::specific_energy_t> { static constexpr char str[] = "J/kg"; };
}
#endif
