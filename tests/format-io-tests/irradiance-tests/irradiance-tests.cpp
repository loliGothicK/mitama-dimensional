#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/irradiance.hpp>
#include "../format_io_common.hpp"

TEST_CASE("irradiance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::irradiance_t{}) == "1 [W/m^2]");
}
TEST_CASE("irradiance quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::irradiance) == "1 [W/m^2]");
}
TEST_CASE("irradiance type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::irradiance)>, mitama::quantity_t<std::decay_t<decltype(kilograms*second<-3>)>>>);
}
