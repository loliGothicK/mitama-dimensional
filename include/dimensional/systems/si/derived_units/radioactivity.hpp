#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTIVITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
struct radioactivity { using is_base_dimension = void; };
using radioactivity_t = make_unit_t<radioactivity>;
inline constexpr radioactivity_t becquerel{};
using radioactivity_r = make_refinement_symbol_t<radioactivity_t>;
}

namespace mitama {
template <> struct symbol_<systems::si::radioactivity> { static constexpr char str[] = "Bq"; };
}
#endif