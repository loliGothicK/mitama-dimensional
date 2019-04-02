#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/radiant_flux.hpp>
#include "../format_io_common.hpp"

TEST_CASE("radiant_flux_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::radiant_flux_t{}) == "1 [W]");
}
TEST_CASE("watt format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::watt) == "1 [W]");
}
