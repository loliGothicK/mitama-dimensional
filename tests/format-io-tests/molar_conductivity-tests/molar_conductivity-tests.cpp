#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/molar_conductivity.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("molar_conductivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_conductivity_t{}) == "1 [S m^2/mol]");
}
TEST_CASE("molar_conductivity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_conductivity) == "1 [S m^2/mol]");
}
TEST_CASE("molar_conductivity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::molar_conductivity)>, mitama::systems::si::quantity_t<std::decay_t<decltype(kilogram<-1>*second<3>*ampere<2>*mol<-1>)>>>);
}
