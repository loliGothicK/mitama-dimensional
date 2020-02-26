#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/energy_density.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("energy_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::energy_density_t{}) == "1 [J/m^3]");
}
TEST_CASE("energy_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::energy_density) == "1 [J/m^3]");
}
TEST_CASE("energy_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::energy_density)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-1>*kilograms*second<-2>)>>>);
}
