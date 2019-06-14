#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CHARGE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct electric_charge_synonym{};
using electric_charge_t = make_synonym_t<electric_charge_synonym, decltype(second<> * ampere<>)>;

inline constexpr electric_charge_t coulomb{};
using electric_charge_r = make_refinement_symbol_t<electric_charge_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::electric_charge_t> { static constexpr char str[] = "C"; };
}
#endif
