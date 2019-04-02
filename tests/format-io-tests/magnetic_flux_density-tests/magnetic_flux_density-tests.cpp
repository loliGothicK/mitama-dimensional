#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/magnetic_flux_density.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_flux_density_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::magnetic_flux_density_t{}) == "1 [T]");
}
TEST_CASE("tesla format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::tesla) == "1 [T]");
}
