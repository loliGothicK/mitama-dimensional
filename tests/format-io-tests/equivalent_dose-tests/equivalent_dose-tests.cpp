#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/equivalent_dose.hpp>
#include "../format_io_common.hpp"

TEST_CASE("equivalent_dose_t format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::sievert_t{}) == "1 [Sv]");
}
TEST_CASE("sievert format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::sievert) == "1 [Sv]");
}
