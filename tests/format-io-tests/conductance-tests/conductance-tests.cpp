#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/conductance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("conductance_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::conductance_t{}) == "1 [S]");
}
TEST_CASE("siemens format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::siemens) == "1 [S]");
}
