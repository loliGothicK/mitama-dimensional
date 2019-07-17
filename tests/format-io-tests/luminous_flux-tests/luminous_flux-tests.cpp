#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/luminous_flux.hpp>
#include "../format_io_common.hpp"

TEST_CASE("luminous_flux_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminous_flux_t{}) == "1 [lm]");
}
TEST_CASE("lumen format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::lumen) == "1 [lm]");
}
