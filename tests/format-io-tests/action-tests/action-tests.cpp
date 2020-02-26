#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/action.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("action format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::action_t{}) == "1 [J s]");
}
TEST_CASE("action quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::action) == "1 [J s]");
}
TEST_CASE("action type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::action)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<2>*kilograms*second<-1>)>>>);
}
