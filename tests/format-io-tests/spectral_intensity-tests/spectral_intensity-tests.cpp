#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/spectral_intensity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("spectral_intensity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spectral_intensity_t{}) == "1 [W/(sr m)]");
}
TEST_CASE("spectral_intensity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::spectral_intensity) == "1 [W/(sr m)]");
}
TEST_CASE("spectral_intensity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::spectral_intensity)>, mitama::quantity_t<std::decay_t<decltype(meters*kilograms*second<-3>/steradian)>>>);
}
