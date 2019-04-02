#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/magnetomotive_force.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetomotive_force format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::magnetomotive_force_t{}) == "1 [A·rad]");
}
TEST_CASE("magnetomotive_force quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::magnetomotive_force) == "1 [A·rad]");
}
TEST_CASE("magnetomotive_force type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::magnetomotive_force)>, mitama::quantity_t<std::decay_t<decltype(ampere<>*radian)>>>);
}
