#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/thermal_conductivity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("thermal_conductivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::thermal_conductivity_t{}) == "1 [W/(m·K)]");
}
TEST_CASE("thermal_conductivity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::thermal_conductivity) == "1 [W/(m·K)]");
}
TEST_CASE("thermal_conductivity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::thermal_conductivity)>, mitama::quantity_t<std::decay_t<decltype(meter<>*kilograms*second<-3>*kelvin<-1>)>>>);
}
