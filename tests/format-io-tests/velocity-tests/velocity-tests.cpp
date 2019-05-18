#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/velocity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("velocity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::velocity_t{}) == "1 [m/s]");
}
TEST_CASE("velocity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::velocity) == "1 [m/s]");
}
TEST_CASE("velocity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::velocity)>, mitama::quantity_t<std::decay_t<decltype(meters/seconds)>>>);
}
