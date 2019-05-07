#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "inductance.hpp"

namespace mitama::si {
template<class> struct permeability_synonym{};
using permeability_t = make_synonym_t<permeability_synonym, decltype(henry / meter<>)>;

inline constexpr permeability_t permeability{};
using permeability_r = make_refinement_symbol_t<permeability_t>;
}

namespace mitama {
template <> struct abbreviation<si::permeability_t> { static constexpr char str[] = "H/m"; };
}
#endif
