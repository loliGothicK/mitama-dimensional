#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/area_density.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("area_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::area_density_t{}) == "1 [kg/m^2]");
}
TEST_CASE("area_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::area_density) == "1 [kg/m^2]");
}
TEST_CASE("area_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::area_density)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-2>*kilograms)>>>);
}
