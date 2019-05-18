#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/solid_angle.hpp>
#include "../format_io_common.hpp"

TEST_CASE("steradian_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::steradian_t{}) == "1 [sr]");
}
TEST_CASE("steradian format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::steradian) == "1 [sr]");
}
