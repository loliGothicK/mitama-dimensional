#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/optical_power.hpp>
#include "../format_io_common.hpp"

TEST_CASE("optical_power format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::optical_power_t{}) == "1 [m^-1]");
}
TEST_CASE("optical_power quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::optical_power) == "1 [m^-1]");
}
TEST_CASE("optical_power type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::optical_power)>, mitama::quantity_t<std::decay_t<decltype(meter<-1>)>>>);
}
