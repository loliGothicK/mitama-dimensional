#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/inductance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("inductance_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::inductance_t{}) == "1 [H]");
}
TEST_CASE("henry format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::henry) == "1 [H]");
}
