#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/catalytic_activity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("catalytic_activity_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::catalytic_activity_t{}) == "1 [kat]");
}
TEST_CASE("katal format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::katal) == "1 [kat]");
}
