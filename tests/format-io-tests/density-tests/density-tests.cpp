#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/density.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::density_t{}) == "1 [kg/m^3]");
}
TEST_CASE("density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::density) == "1 [kg/m^3]");
}
TEST_CASE("density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::density)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-3>*kilograms)>>>);
}
