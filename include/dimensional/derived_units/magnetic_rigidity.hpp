#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_RIGIDITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_RIGIDITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "magnetic_flux_density.hpp"

namespace mitama::si {
template<class> struct magnetic_rigidity_repr{};
using magnetic_rigidity_t = make_synonym_t<magnetic_rigidity_repr, decltype(tesla * meter<>)>;

inline constexpr magnetic_rigidity_t magnetic_rigidity{};
using magnetic_rigidity_r = make_refiment_symbol_t<magnetic_rigidity_t>;
}

namespace mitama {
template <> struct abbreviation<si::magnetic_rigidity_t> { static constexpr char str[] = "T·m"; };
}
#endif
