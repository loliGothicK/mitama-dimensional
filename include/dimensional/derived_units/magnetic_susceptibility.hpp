#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_SUSCEPTIBILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_SUSCEPTIBILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "inductance.hpp"

namespace mitama::si {
template<class> struct magnetic_susceptibility_repr{};
using magnetic_susceptibility_t = make_synonym_t<magnetic_susceptibility_repr, decltype(meter<> / henry)>;

inline constexpr magnetic_susceptibility_t magnetic_susceptibility{};
using magnetic_susceptibility_r = make_refinement_symbol_t<magnetic_susceptibility_t>;
}

namespace mitama {
template <> struct abbreviation<si::magnetic_susceptibility_t> { static constexpr char str[] = "m/H"; };
}
#endif
