#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/permeability.hpp>
#include "../format_io_common.hpp"

TEST_CASE("permeability format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::permeability_t{}) == "1 [H/m]");
}
TEST_CASE("permeability quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::permeability) == "1 [H/m]");
}
TEST_CASE("permeability type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::permeability)>, mitama::quantity_t<std::decay_t<decltype(meter<>*kilogram<>*second<-2>*ampere<-2>)>>>);
}
