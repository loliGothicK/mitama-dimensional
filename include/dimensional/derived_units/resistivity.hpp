#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_RESISTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "resistance.hpp"

namespace mitama::si {
template<class> struct resistivity_repr{};
using resistivity_t = make_synonym_t<resistivity_repr, decltype(ohm * meter<>)>;

inline constexpr resistivity_t resistivity{};
}

namespace mitama {
template <> struct abbreviation<si::resistivity_t> { static constexpr char str[] = "Ω·m"; };
}
#endif
