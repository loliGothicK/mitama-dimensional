#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/luminance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("luminance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminance_t{}) == "1 [cd/m^2]");
}
TEST_CASE("luminance quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::luminance) == "1 [cd/m^2]");
}
TEST_CASE("luminance type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::luminance)>, mitama::quantity_t<std::decay_t<decltype(meter<-2>*candelas)>>>);
}
