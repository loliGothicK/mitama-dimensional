#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/volumetric_flow.hpp>
#include "../format_io_common.hpp"

TEST_CASE("volumetric_flow format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::volumetric_flow_t{}) == "1 [m^3/s]");
}
TEST_CASE("volumetric_flow quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::volumetric_flow) == "1 [m^3/s]");
}
TEST_CASE("volumetric_flow type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::volumetric_flow)>, mitama::quantity_t<std::decay_t<decltype(meter<3>*second<-1>)>>>);
}
