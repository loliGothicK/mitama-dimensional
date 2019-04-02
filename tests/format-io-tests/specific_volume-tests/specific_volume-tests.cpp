#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/specific_volume.hpp>
#include "../format_io_common.hpp"

TEST_CASE("specific_volume format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::specific_volume_t{}) == "1 [m^3/kg]");
}
TEST_CASE("specific_volume quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::specific_volume) == "1 [m^3/kg]");
}
TEST_CASE("specific_volume type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::specific_volume)>, mitama::quantity_t<std::decay_t<decltype(meter<3>*kilogram<-1>)>>>);
}
