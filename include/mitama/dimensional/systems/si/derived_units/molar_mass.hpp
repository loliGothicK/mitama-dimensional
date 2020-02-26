#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_MASS_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_MASS_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct molar_mass_synonym{};
using molar_mass_t = make_synonym_t<molar_mass_synonym, decltype(kilogram<> / mol<>)>;

inline constexpr molar_mass_t molar_mass{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::molar_mass_t> { static constexpr char str[] = "kg/mol"; };
}
#endif
