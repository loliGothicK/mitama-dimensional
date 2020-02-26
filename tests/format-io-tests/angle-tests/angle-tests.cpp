#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/angle.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("radian_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::radian_t{}) == "1 [rad]");
}
TEST_CASE("radian format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::radian) == "1 [rad]");
}
