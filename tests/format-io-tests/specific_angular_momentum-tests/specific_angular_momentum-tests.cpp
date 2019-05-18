#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/specific_angular_momentum.hpp>
#include "../format_io_common.hpp"

TEST_CASE("specific_angular_momentum format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::specific_angular_momentum_t{}) == "1 [N·m·s/kg]");
}
TEST_CASE("specific_angular_momentum quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::specific_angular_momentum) == "1 [N·m·s/kg]");
}
TEST_CASE("specific_angular_momentum type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::specific_angular_momentum)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*second<-1>)>>>);
}
