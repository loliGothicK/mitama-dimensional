#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_ENERGY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "luminous_flux.hpp"

namespace mitama::si {
template<class> struct luminous_energy_repr{};
using luminous_energy_t = make_synonym_t<luminous_energy_repr, decltype(lumen * second<>)>;

inline constexpr luminous_energy_t luminous_energy{};
using luminous_energy_r = make_refiment_symbol_t<luminous_energy_t>;
}

namespace mitama {
template <> struct abbreviation<si::luminous_energy_t> { static constexpr char str[] = "lm·s"; };
}
#endif
