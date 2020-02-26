#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/magnetic_field_strength.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_field_strength format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_field_strength_t{}) == "1 [A/m]");
}
TEST_CASE("magnetic_field_strength quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_field_strength) == "1 [A/m]");
}
TEST_CASE("magnetic_field_strength type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::magnetic_field_strength)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-1>*ampere<>)>>>);
}
