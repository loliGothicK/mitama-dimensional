#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/angular_acceleration.hpp>
#include "../format_io_common.hpp"

TEST_CASE("angular_acceleration format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::angular_acceleration_t{}) == "1 [rad/s^2]");
}
TEST_CASE("angular_acceleration quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::angular_acceleration) == "1 [rad/s^2]");
}
TEST_CASE("angular_acceleration type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::angular_acceleration)>, mitama::quantity_t<std::decay_t<decltype(radian*second<-2>)>>>);
}
