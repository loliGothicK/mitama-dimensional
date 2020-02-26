#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/thermal_expansion_coefficient.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("thermal_expansion_coefficient format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::thermal_expansion_coefficient_t{}) == "1 [K^-1]");
}
TEST_CASE("thermal_expansion_coefficient quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::thermal_expansion_coefficient) == "1 [K^-1]");
}
TEST_CASE("thermal_expansion_coefficient type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::thermal_expansion_coefficient)>, mitama::systems::si::quantity_t<std::decay_t<decltype(kelvin<-1>)>>>);
}
