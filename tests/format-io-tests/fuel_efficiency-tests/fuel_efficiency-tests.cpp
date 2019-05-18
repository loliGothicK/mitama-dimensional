#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/fuel_efficiency.hpp>
#include "../format_io_common.hpp"

TEST_CASE("fuel_efficiency format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::fuel_efficiency_t{}) == "1 [m/m^3]");
}
TEST_CASE("fuel_efficiency quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::fuel_efficiency) == "1 [m/m^3]");
}
TEST_CASE("fuel_efficiency type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::fuel_efficiency)>, mitama::quantity_t<std::decay_t<decltype(meter<-2>)>>>);
}
