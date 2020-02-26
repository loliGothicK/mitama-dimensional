#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/magnetic_rigidity.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_rigidity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_rigidity_t{}) == "1 [T m]");
}
TEST_CASE("magnetic_rigidity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_rigidity) == "1 [T m]");
}
TEST_CASE("magnetic_rigidity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::magnetic_rigidity)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<>*kilogram<>*second<-2>*ampere<-1>)>>>);
}
