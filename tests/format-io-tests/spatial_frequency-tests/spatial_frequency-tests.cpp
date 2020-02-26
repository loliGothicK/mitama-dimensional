#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/spatial_frequency.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("spatial_frequency format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spatial_frequency_t{}) == "1 [m^-1]");
}
TEST_CASE("spatial_frequency quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spatial_frequency) == "1 [m^-1]");
}
TEST_CASE("spatial_frequency type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::spatial_frequency)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-1>)>>>);
}
