#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/radiance.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("radiance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::radiance_t{}) == "1 [W/(sr m^2)]");
}
TEST_CASE("radiance quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::radiance) == "1 [W/(sr m^2)]");
}
TEST_CASE("radiance type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::radiance)>, mitama::systems::si::quantity_t<std::decay_t<decltype(kilograms/steradian/second<3>)>>>);
}
