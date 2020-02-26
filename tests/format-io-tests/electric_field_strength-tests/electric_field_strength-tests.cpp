#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/electric_field_strength.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("electric_field_strength format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electric_field_strength_t{}) == "1 [V/m]");
}
TEST_CASE("electric_field_strength quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electric_field_strength) == "1 [V/m]");
}
TEST_CASE("electric_field_strength type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::electric_field_strength)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<>*kilogram<>*second<-3>*ampere<-1>)>>>);
}
