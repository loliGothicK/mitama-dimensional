#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/energy.hpp>
#include "../format_io_common.hpp"

TEST_CASE("energy_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::energy_t{}) == "1 [J]");
}
TEST_CASE("joule format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::joule) == "1 [J]");
}
