#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/voltage.hpp>
#include "../format_io_common.hpp"

TEST_CASE("voltage_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::voltage_t{}) == "1 [V]");
}
TEST_CASE("volts format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::volts) == "1 [V]");
}
