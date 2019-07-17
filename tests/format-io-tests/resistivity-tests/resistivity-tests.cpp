#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/resistivity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("resistivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::resistivity_t{}) == "1 [Ω m]");
}
TEST_CASE("resistivity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::resistivity) == "1 [Ω m]");
}
TEST_CASE("resistivity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::resistivity)>, mitama::quantity_t<std::decay_t<decltype(meter<3>*kilogram<>*second<-3>*ampere<-2>)>>>);
}
