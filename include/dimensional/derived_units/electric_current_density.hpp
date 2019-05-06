#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CURRENT_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CURRENT_DENSITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"


namespace mitama::si {
template<class> struct electric_current_density_repr{};
using electric_current_density_t = make_synonym_t<electric_current_density_repr, decltype(ampere<> / meter<2>)>;

inline constexpr electric_current_density_t electric_current_density{};
using electric_current_density_r = make_refinement_symbol_t<electric_current_density_t>;
}

namespace mitama {
template <> struct abbreviation<si::electric_current_density_t> { static constexpr char str[] = "A/m^2"; };
}
#endif
