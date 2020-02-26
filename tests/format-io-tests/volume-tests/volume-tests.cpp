#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/volume.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("volume format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::volume_t{}) == "1 [m^3]");
}
TEST_CASE("volume quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::volume) == "1 [m^3]");
}
TEST_CASE("volume type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::volume)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<3>)>>>);
}
