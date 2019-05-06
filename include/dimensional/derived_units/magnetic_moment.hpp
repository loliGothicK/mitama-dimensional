#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_MOMENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_MOMENT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "magnetic_flux.hpp"

namespace mitama::si {
template<class> struct magnetic_moment_repr{};
using magnetic_moment_t = make_synonym_t<magnetic_moment_repr, decltype(weber * meter<>)>;

inline constexpr magnetic_moment_t magnetic_moment{};
using magnetic_moment_r = make_refinement_symbol_t<magnetic_moment_t>;
}

namespace mitama {
template <> struct abbreviation<si::magnetic_moment_t> { static constexpr char str[] = "Wb·m"; };
}
#endif
