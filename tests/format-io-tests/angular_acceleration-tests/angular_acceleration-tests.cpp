#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/angular_acceleration.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("angular_acceleration format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::angular_acceleration_t{}) == "1 [rad/s^2]");
}
TEST_CASE("angular_acceleration quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::angular_acceleration) == "1 [rad/s^2]");
}
TEST_CASE("angular_acceleration type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::angular_acceleration)>, mitama::systems::si::quantity_t<std::decay_t<decltype(radian*second<-2>)>>>);
}
