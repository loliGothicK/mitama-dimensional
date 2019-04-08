#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMITTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMITTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "capacitance.hpp"

namespace mitama::si {
template<class> struct permittivity_repr{};
using permittivity_t = make_synonym_t<permittivity_repr, decltype(farad / meter<>)>;

inline constexpr permittivity_t permittivity{};
}

namespace mitama {
template <> struct abbreviation<si::permittivity_t> { static constexpr char str[] = "F/m"; };
}
#endif
