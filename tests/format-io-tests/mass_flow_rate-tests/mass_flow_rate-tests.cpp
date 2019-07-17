#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/mass_flow_rate.hpp>
#include "../format_io_common.hpp"

TEST_CASE("mass_flow_rate format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::mass_flow_rate_t{}) == "1 [kg/s]");
}
TEST_CASE("mass_flow_rate quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::mass_flow_rate) == "1 [kg/s]");
}
TEST_CASE("mass_flow_rate type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::mass_flow_rate)>, mitama::quantity_t<std::decay_t<decltype(kilograms/seconds)>>>);
}
