#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/linear_charge_density.hpp>
#include "../format_io_common.hpp"

TEST_CASE("linear_charge_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::linear_charge_density_t{}) == "1 [C/m]");
}
TEST_CASE("linear_charge_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::linear_charge_density) == "1 [C/m]");
}
TEST_CASE("linear_charge_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::linear_charge_density)>, mitama::quantity_t<std::decay_t<decltype(meter<-1>*second<>*ampere<>)>>>);
}
