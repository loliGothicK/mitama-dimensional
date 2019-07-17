#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMITTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PERMITTIVITY_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>
#include "capacitance.hpp"

namespace mitama::systems::si {
template<class> struct permittivity_synonym{};
using permittivity_t = make_synonym_t<permittivity_synonym, decltype(farad / meter<>)>;

inline constexpr permittivity_t permittivity{};
using permittivity_r = make_refinement_symbol_t<permittivity_t>;
}

namespace mitama {
template <> struct  abbreviation_<systems::si::permittivity_t> { static constexpr char str[] = "F/m"; };
}
#endif
