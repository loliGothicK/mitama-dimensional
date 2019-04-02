#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/radiant_exposure.hpp>
#include "../format_io_common.hpp"

TEST_CASE("radiant_exposure format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::radiant_exposure_t{}) == "1 [J/m^2]");
}
TEST_CASE("radiant_exposure quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::radiant_exposure) == "1 [J/m^2]");
}
TEST_CASE("radiant_exposure type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::radiant_exposure)>, mitama::quantity_t<std::decay_t<decltype(kilograms*second<-2>)>>>);
}
