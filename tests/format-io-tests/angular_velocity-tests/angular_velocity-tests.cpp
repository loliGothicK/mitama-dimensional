#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/angular_velocity.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("angular_velocity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::angular_velocity_t{}) == "1 [rad/s]");
}
TEST_CASE("angular_velocity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::angular_velocity) == "1 [rad/s]");
}
TEST_CASE("angular_velocity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::angular_velocity)>, mitama::systems::si::quantity_t<std::decay_t<decltype(radian*second<-1>)>>>);
}
