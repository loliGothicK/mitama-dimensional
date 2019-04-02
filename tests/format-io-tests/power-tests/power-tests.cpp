#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/power.hpp>
#include "../format_io_common.hpp"

TEST_CASE("power_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::power_t{}) == "1 [W]");
}
TEST_CASE("watt format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::watt) == "1 [W]");
}
