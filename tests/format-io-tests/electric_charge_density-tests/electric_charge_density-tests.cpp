#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/electric_charge_density.hpp>
#include "../format_io_common.hpp"

TEST_CASE("electric_charge_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::electric_charge_density_t{}) == "1 [C/m^3]");
}
TEST_CASE("electric_charge_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::electric_charge_density) == "1 [C/m^3]");
}
TEST_CASE("electric_charge_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::electric_charge_density)>, mitama::quantity_t<std::decay_t<decltype(meter<-3>*second<>*ampere<>)>>>);
}
