#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/electrical_conductivity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("electrical_conductivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electrical_conductivity_t{}) == "1 [S/m]");
}
TEST_CASE("electrical_conductivity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electrical_conductivity) == "1 [S/m]");
}
TEST_CASE("electrical_conductivity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::electrical_conductivity)>, mitama::quantity_t<std::decay_t<decltype(meter<-3>*kilogram<-1>*second<3>*ampere<2>)>>>);
}
