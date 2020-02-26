#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/heat_capacity.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("heat_capacity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::heat_capacity_t{}) == "1 [J/K]");
}
TEST_CASE("heat_capacity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::heat_capacity) == "1 [J/K]");
}
TEST_CASE("heat_capacity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::heat_capacity)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<2>*kilograms*second<-2>*kelvin<-1>)>>>);
}
