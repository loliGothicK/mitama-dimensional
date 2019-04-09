#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMEABILITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "inductance.hpp"

namespace mitama::si {
template<class> struct permeability_repr{};
using permeability_t = make_synonym_t<permeability_repr, decltype(henry / meter<>)>;

inline constexpr permeability_t permeability{};
}

namespace mitama {
template <> struct abbreviation<si::permeability_t> { static constexpr char str[] = "H/m"; };
}
#endif
