#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/luminous_efficacy.hpp>
#include "../format_io_common.hpp"

TEST_CASE("luminous_efficacy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminous_efficacy_t{}) == "1 [lm/W]");
}
TEST_CASE("luminous_efficacy quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminous_efficacy) == "1 [lm/W]");
}
TEST_CASE("luminous_efficacy type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::luminous_efficacy)>, mitama::quantity_t<std::decay_t<decltype(meter<-2>*kilogram<-1>*second<3>*candelas*steradian)>>>);
}
