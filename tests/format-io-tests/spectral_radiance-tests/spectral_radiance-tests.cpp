#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/spectral_radiance.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("spectral_radiance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spectral_radiance_t{}) == "1 [W/(sr m^3)]");
}
TEST_CASE("spectral_radiance quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spectral_radiance) == "1 [W/(sr m^3)]");
}
TEST_CASE("spectral_radiance type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::spectral_radiance)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-1>*kilograms*second<-3>/steradian)>>>);
}
