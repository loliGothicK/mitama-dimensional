#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/thermal_diffusivity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("thermal_diffusivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::thermal_diffusivity_t{}) == "1 [m^2/s]");
}
TEST_CASE("thermal_diffusivity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::thermal_diffusivity) == "1 [m^2/s]");
}
TEST_CASE("thermal_diffusivity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::thermal_diffusivity)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*second<-1>)>>>);
}
