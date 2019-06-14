#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/luminous_energy.hpp>
#include "../format_io_common.hpp"

TEST_CASE("luminous_energy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminous_energy_t{}) == "1 [lm s]");
}
TEST_CASE("luminous_energy quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminous_energy) == "1 [lm s]");
}
TEST_CASE("luminous_energy type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::luminous_energy)>, mitama::quantity_t<std::decay_t<decltype(seconds*candelas*steradian)>>>);
}
