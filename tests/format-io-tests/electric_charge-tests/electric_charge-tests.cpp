#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/electric_charge.hpp>
#include "../format_io_common.hpp"

TEST_CASE("electric_charge_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electric_charge_t{}) == "1 [C]");
}
TEST_CASE("coulomb format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::coulomb) == "1 [C]");
}
