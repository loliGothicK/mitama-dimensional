#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/acceleration.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("acceleration format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::acceleration_t{}) == "1 [m/s^2]");
}
TEST_CASE("acceleration quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::acceleration) == "1 [m/s^2]");
}
TEST_CASE("acceleration type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::acceleration)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meters/second<2>)>>>);
}
