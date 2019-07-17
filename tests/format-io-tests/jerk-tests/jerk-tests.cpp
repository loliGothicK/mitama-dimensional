#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/jerk.hpp>
#include "../format_io_common.hpp"

TEST_CASE("jerk format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::jerk_t{}) == "1 [m/s^3]");
}
TEST_CASE("jerk quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::jerk) == "1 [m/s^3]");
}
TEST_CASE("jerk type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::jerk)>, mitama::quantity_t<std::decay_t<decltype(meters/second<3>)>>>);
}
