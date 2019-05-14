#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/radiant_intensity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("radiant_intensity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::radiant_intensity_t{}) == "1 [W/sr]");
}
TEST_CASE("radiant_intensity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::radiant_intensity) == "1 [W/sr]");
}
TEST_CASE("radiant_intensity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::radiant_intensity)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*kilograms*second<-3>/steradian)>>>);
}
