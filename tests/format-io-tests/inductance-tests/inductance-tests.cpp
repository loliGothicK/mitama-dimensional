#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/inductance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("inductance_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::inductance_t{}) == "1 [H]");
}
TEST_CASE("henry format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::henry) == "1 [H]");
}
