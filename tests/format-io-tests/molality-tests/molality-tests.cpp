#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/molality.hpp>
#include "../format_io_common.hpp"

TEST_CASE("molality format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molality_t{}) == "1 [mol/kg]");
}
TEST_CASE("molality quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molality) == "1 [mol/kg]");
}
TEST_CASE("molality type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::molality)>, mitama::quantity_t<std::decay_t<decltype(kilogram<-1>*mol<>)>>>);
}
