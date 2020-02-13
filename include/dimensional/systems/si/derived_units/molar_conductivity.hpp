#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_CONDUCTIVITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

#include "conductance.hpp"

namespace mitama::systems::si {
template<class> struct molar_conductivity_synonym{};
using molar_conductivity_t = make_synonym_t<molar_conductivity_synonym, decltype(siemens * meter<2> / mol<>)>;

inline constexpr molar_conductivity_t molar_conductivity{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::molar_conductivity_t> { static constexpr char str[] = "S m^2/mol"; };
}
#endif
