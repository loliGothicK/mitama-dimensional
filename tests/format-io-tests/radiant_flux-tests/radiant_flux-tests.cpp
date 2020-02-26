#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/radiant_flux.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("radiant_flux_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::radiant_flux_t{}) == "1 [W]");
}
TEST_CASE("watt format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::watt) == "1 [W]");
}
