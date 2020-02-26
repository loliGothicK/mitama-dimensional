#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/impedance.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("impedance_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::impedance_t{}) == "1 [Ω]");
}
TEST_CASE("ohm format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::ohm) == "1 [Ω]");
}
