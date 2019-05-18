#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/spectral_power.hpp>
#include "../format_io_common.hpp"

TEST_CASE("spectral_power format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spectral_power_t{}) == "1 [W/m]");
}
TEST_CASE("spectral_power quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spectral_power) == "1 [W/m]");
}
TEST_CASE("spectral_power type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::spectral_power)>, mitama::quantity_t<std::decay_t<decltype(meters*kilograms*second<-3>)>>>);
}
