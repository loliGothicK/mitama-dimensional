#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLARITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLARITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct molarity_synonym{};
using molarity_t = make_synonym_t<molarity_synonym, decltype(mol<> / meter<3>)>;

inline constexpr molarity_t molarity{};
using molarity_r = make_refinement_symbol_t<molarity_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::molarity_t> { static constexpr char str[] = "mol/m^3"; };
}
#endif
