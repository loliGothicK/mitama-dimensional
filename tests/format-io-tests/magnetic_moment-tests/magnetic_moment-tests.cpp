#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/magnetic_moment.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetic_moment format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_moment_t{}) == "1 [Wb m]");
}
TEST_CASE("magnetic_moment quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::magnetic_moment) == "1 [Wb m]");
}
TEST_CASE("magnetic_moment type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::magnetic_moment)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<3>*kilogram<>*second<-2>*ampere<-1>)>>>);
}
