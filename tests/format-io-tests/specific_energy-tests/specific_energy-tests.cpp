#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/specific_energy.hpp>
#include "../format_io_common.hpp"

TEST_CASE("specific_energy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::specific_energy_t{}) == "1 [J/kg]");
}
TEST_CASE("specific_energy quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::specific_energy) == "1 [J/kg]");
}
TEST_CASE("specific_energy type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::specific_energy)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*second<-2>)>>>);
}
