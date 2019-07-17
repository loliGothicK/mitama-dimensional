#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/molar_energy.hpp>
#include "../format_io_common.hpp"

TEST_CASE("molar_energy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_energy_t{}) == "1 [J/mol]");
}
TEST_CASE("molar_energy quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_energy) == "1 [J/mol]");
}
TEST_CASE("molar_energy type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::molar_energy)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*kilograms*second<-2>*mol<-1>)>>>);
}
