#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/snap.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("snap format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::snap_t{}) == "1 [m/s^4]");
}
TEST_CASE("snap quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::snap) == "1 [m/s^4]");
}
TEST_CASE("snap type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::snap)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meters/second<4>)>>>);
}
