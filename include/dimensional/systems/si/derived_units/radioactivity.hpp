#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTIVITY_HPP
#include <dimensional/systems/si/base_dimension/radio_activity.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>


namespace mitama::systems::si {
using radio_activity_base_unit = base_units<radio_activity, 0>;
using radioactivity_t = typename radio_activity_base_unit::unit_type;
inline constexpr radioactivity_t becquerel{};

}

namespace mitama {
template <> struct symbol_<systems::si::radio_activity, 0> { static constexpr char str[] = "Bq"; };
}
#endif
