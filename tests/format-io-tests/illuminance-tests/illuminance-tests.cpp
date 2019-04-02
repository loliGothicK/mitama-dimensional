#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/illuminance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("illuminance_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::illuminance_t{}) == "1 [lx]");
}
TEST_CASE("lux format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::lux) == "1 [lx]");
}
