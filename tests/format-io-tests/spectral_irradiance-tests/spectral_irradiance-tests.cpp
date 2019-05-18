#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/spectral_irradiance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("spectral_irradiance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spectral_irradiance_t{}) == "1 [W/m^3]");
}
TEST_CASE("spectral_irradiance quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spectral_irradiance) == "1 [W/m^3]");
}
TEST_CASE("spectral_irradiance type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::spectral_irradiance)>, mitama::quantity_t<std::decay_t<decltype(meter<-1>*kilograms*second<-3>)>>>);
}
