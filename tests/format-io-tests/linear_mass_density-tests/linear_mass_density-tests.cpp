#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/linear_mass_density.hpp>
#include "../format_io_common.hpp"

TEST_CASE("linear_mass_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::linear_mass_density_t{}) == "1 [kg/m]");
}
TEST_CASE("linear_mass_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::linear_mass_density) == "1 [kg/m]");
}
TEST_CASE("linear_mass_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::linear_mass_density)>, mitama::quantity_t<std::decay_t<decltype(meter<-1>*kilograms)>>>);
}
