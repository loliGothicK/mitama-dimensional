#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/heat_flux_density.hpp>
#include "../format_io_common.hpp"

TEST_CASE("heat_flux_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::heat_flux_density_t{}) == "1 [W/m^2]");
}
TEST_CASE("heat_flux_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::heat_flux_density) == "1 [W/m^2]");
}
TEST_CASE("heat_flux_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::heat_flux_density)>, mitama::quantity_t<std::decay_t<decltype(kilograms*second<-3>)>>>);
}
