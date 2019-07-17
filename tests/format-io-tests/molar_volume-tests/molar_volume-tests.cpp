#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/molar_volume.hpp>
#include "../format_io_common.hpp"

TEST_CASE("molar_volume format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_volume_t{}) == "1 [m^3/mol]");
}
TEST_CASE("molar_volume quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_volume) == "1 [m^3/mol]");
}
TEST_CASE("molar_volume type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::molar_volume)>, mitama::quantity_t<std::decay_t<decltype(meter<3>*mol<-1>)>>>);
}
