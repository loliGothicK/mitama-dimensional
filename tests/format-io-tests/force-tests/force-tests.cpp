#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/force.hpp>
#include "../format_io_common.hpp"

TEST_CASE("force_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::force_t{}) == "1 [N]");
}
TEST_CASE("newton format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::newton) == "1 [N]");
}
