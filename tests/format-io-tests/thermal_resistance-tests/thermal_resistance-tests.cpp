#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/thermal_resistance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("thermal_resistance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::thermal_resistance_t{}) == "1 [K/W]");
}
TEST_CASE("thermal_resistance quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::thermal_resistance) == "1 [K/W]");
}
TEST_CASE("thermal_resistance type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::thermal_resistance)>, mitama::quantity_t<std::decay_t<decltype(meter<-2>*kilogram<-1>*second<3>*kelvins)>>>);
}
