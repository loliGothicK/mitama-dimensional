#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/molar_mass.hpp>
#include "../format_io_common.hpp"

TEST_CASE("molar_mass format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_mass_t{}) == "1 [kg/mol]");
}
TEST_CASE("molar_mass quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_mass) == "1 [kg/mol]");
}
TEST_CASE("molar_mass type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::molar_mass)>, mitama::quantity_t<std::decay_t<decltype(kilogram<>/mol<>)>>>);
}
