#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/catalytic_efficiency.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("catalytic_efficiency format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::catalytic_efficiency_t{}) == "1 [m^3/(mol s)]");
}
TEST_CASE("catalytic_efficiency quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::catalytic_efficiency) == "1 [m^3/(mol s)]");
}
TEST_CASE("catalytic_efficiency type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::catalytic_efficiency)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<3>*second<-1>*mol<-1>)>>>);
}
