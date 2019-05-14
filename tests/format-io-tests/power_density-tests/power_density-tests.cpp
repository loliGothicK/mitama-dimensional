#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/power_density.hpp>
#include "../format_io_common.hpp"

TEST_CASE("power_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::power_density_t{}) == "1 [W/m^3]");
}
TEST_CASE("power_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::power_density) == "1 [W/m^3]");
}
TEST_CASE("power_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::power_density)>, mitama::quantity_t<std::decay_t<decltype(meter<-1>*kilograms*second<-3>)>>>);
}
