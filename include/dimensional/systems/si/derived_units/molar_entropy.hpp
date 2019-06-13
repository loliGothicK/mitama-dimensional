#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENTROPY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_ENTROPY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "energy.hpp"

namespace mitama::systems::si {
template<class> struct molar_entropy_synonym{};
using molar_entropy_t = make_synonym_t<molar_entropy_synonym, decltype( joule / (kelvin<> * mol<>) )>;

inline constexpr molar_entropy_t molar_entropy{};
using molar_entropy_r = make_refinement_symbol_t<molar_entropy_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_HEAT_CAPACITY_HPP
namespace mitama {
template <> struct abbreviation<systems::si::molar_entropy_t> { static constexpr char str[] = "J/(K mol)"; };
}
#endif

#endif
