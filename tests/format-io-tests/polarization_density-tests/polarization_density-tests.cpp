#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/polarization_density.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("polarization_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::polarization_density_t{}) == "1 [C/m^2]");
}
TEST_CASE("polarization_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::polarization_density) == "1 [C/m^2]");
}
TEST_CASE("polarization_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::polarization_density)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-2>*seconds*ampere<>)>>>);
}
