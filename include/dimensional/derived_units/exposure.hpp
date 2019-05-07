#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_EXPOSURE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_EXPOSURE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"
#include "../refinement.hpp"
#include "electric_charge.hpp"

namespace mitama::si {
template<class> struct exposure_synonym{};
using exposure_t = make_synonym_t<exposure_synonym, decltype(coulomb / kilogram<>)>;

inline constexpr exposure_t exposure{};
using exposure_r = make_refinement_symbol_t<exposure_t>;
}

namespace mitama {
template <> struct abbreviation<si::exposure_t> { static constexpr char str[] = "C/kg"; };
}
#endif
