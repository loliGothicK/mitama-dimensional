#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/magnetic_susceptibility.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_susceptibility format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_susceptibility_t{}) == "1 [m/H]");
}
TEST_CASE("magnetic_susceptibility quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_susceptibility) == "1 [m/H]");
}
TEST_CASE("magnetic_susceptibility type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::magnetic_susceptibility)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-1>*kilogram<-1>*second<2>*ampere<2>)>>>);
}
