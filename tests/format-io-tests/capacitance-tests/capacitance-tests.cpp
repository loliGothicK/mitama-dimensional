#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/capacitance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("capacitance_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::capacitance_t{}) == "1 [F]");
}
TEST_CASE("farad format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::farad) == "1 [F]");
}