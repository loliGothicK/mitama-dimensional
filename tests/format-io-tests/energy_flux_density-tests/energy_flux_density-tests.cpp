#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/energy_flux_density.hpp>
#include "../format_io_common.hpp"

TEST_CASE("energy_flux_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::energy_flux_density_t{}) == "1 [J/(m^2·s)]");
}
TEST_CASE("energy_flux_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::energy_flux_density) == "1 [J/(m^2·s)]");
}
TEST_CASE("energy_flux_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::energy_flux_density)>, mitama::quantity_t<std::decay_t<decltype(kilograms*second<-3>)>>>);
}
