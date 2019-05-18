#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DOSE_EQUIVALENCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DOSE_EQUIVALENCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
struct equivalent_dose { using is_base_dimension = void; };
using sievert_t = make_unit_t<equivalent_dose>;
inline constexpr sievert_t sievert{};
using equivalent_dose_r = make_refinement_symbol_t<sievert_t>;
}

namespace mitama {
template <> struct symbol_<systems::si::equivalent_dose> { static constexpr char str[] = "Sv"; };
}
#endif