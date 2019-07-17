#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTIVITY_HPP
#include <mitama/dimensional/systems/si/base_dimension/radio_activity.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/refinement.hpp>

namespace mitama::systems::si {
using radio_activity_base_unit = base_units<radio_activity, 0>;
using radioactivity_t = typename radio_activity_base_unit::unit_type;
inline constexpr radioactivity_t becquerel{};
using radioactivity_r = make_refinement_symbol_t<radioactivity_t>;
}

namespace mitama {
template <> struct symbol_<systems::si::radio_activity, 0> { static constexpr char str[] = "Bq"; };
}
#endif
