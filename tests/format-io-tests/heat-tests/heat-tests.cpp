#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/heat.hpp>
#include "../format_io_common.hpp"

TEST_CASE("heat_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::heat_t{}) == "1 [J]");
}
TEST_CASE("joule format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::joule) == "1 [J]");
}
