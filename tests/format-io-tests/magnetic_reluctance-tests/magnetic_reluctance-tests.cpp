#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/magnetic_reluctance.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_reluctance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_reluctance_t{}) == "1 [H^-1]");
}
TEST_CASE("magnetic_reluctance quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_reluctance) == "1 [H^-1]");
}
TEST_CASE("magnetic_reluctance type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::magnetic_reluctance)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-2>*kilogram<-1>*second<2>*ampere<2>)>>>);
}
