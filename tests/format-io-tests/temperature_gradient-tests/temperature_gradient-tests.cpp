#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/temperature_gradient.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("temperature_gradient format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::temperature_gradient_t{}) == "1 [K/m]");
}
TEST_CASE("temperature_gradient quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::temperature_gradient) == "1 [K/m]");
}
TEST_CASE("temperature_gradient type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::temperature_gradient)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-1>*kelvins)>>>);
}
