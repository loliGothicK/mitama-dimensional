#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/permittivity.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("permittivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::permittivity_t{}) == "1 [F/m]");
}
TEST_CASE("permittivity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::permittivity) == "1 [F/m]");
}
TEST_CASE("permittivity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::permittivity)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-3>*kilogram<-1>*second<4>*ampere<2>)>>>);
}
