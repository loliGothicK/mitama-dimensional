#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENERGY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>

#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct molar_energy_synonym{};
using molar_energy_t = make_synonym_t<molar_energy_synonym, decltype(joule / mol<>)>;

inline constexpr molar_energy_t molar_energy{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::molar_energy_t> { static constexpr char str[] = "J/mol"; };
}
#endif
