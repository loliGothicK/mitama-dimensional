#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/surface_tension.hpp>
#include "../format_io_common.hpp"

TEST_CASE("surface_tension format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::surface_tension_t{}) == "1 [N/m]");
}
TEST_CASE("surface_tension quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::surface_tension) == "1 [N/m]");
}
TEST_CASE("surface_tension type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::surface_tension)>, mitama::quantity_t<std::decay_t<decltype(kilograms*second<-2>)>>>);
}
