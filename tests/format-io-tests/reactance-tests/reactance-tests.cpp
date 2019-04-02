#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/reactance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("reactance_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::reactance_t{}) == "1 [Ω]");
}
TEST_CASE("ohm format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::ohm) == "1 [Ω]");
}
