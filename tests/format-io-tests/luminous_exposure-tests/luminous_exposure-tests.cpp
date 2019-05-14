#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/luminous_exposure.hpp>
#include "../format_io_common.hpp"

TEST_CASE("luminous_exposure format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminous_exposure_t{}) == "1 [lx·s]");
}
TEST_CASE("luminous_exposure quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminous_exposure) == "1 [lx·s]");
}
TEST_CASE("luminous_exposure type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::luminous_exposure)>, mitama::quantity_t<std::decay_t<decltype(meter<-2>*seconds*candelas*steradian)>>>);
}
