#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/magnetic_flux.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_flux_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::magnetic_flux_t{}) == "1 [Wb]");
}
TEST_CASE("weber format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::weber) == "1 [Wb]");
}
