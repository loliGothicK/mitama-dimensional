#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/electric_potential.hpp>
#include "../format_io_common.hpp"

TEST_CASE("electric_potential_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electric_potential_t{}) == "1 [V]");
}
TEST_CASE("volts format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::volts) == "1 [V]");
}
