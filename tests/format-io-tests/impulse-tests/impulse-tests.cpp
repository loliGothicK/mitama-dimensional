#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/impulse.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("impulse format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::impulse_t{}) == "1 [N s]");
}
TEST_CASE("impulse quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::impulse) == "1 [N s]");
}
TEST_CASE("impulse type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::impulse)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meters*kilograms*second<-1>)>>>);
}
