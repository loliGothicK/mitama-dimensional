#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/electric_displacement_field.hpp>
#include "../format_io_common.hpp"

TEST_CASE("electric_displacement_field format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electric_displacement_field_t{}) == "1 [C/m^2]");
}
TEST_CASE("electric_displacement_field quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electric_displacement_field) == "1 [C/m^2]");
}
TEST_CASE("electric_displacement_field type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::electric_displacement_field)>, mitama::quantity_t<std::decay_t<decltype(meter<-2>*seconds*ampere<>)>>>);
}
