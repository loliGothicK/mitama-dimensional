#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/absorbed_dose.hpp>
#include "../format_io_common.hpp"

TEST_CASE("sievert_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::absorbed_dose_t{}) == "1 [Gy]");
}
TEST_CASE("gray format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::gray) == "1 [Gy]");
}
