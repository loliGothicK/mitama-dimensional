#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/power.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("power_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::power_t{}) == "1 [W]");
}
TEST_CASE("watt format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::watt) == "1 [W]");
}
