#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/electron_mobility.hpp>
#include "../format_io_common.hpp"

TEST_CASE("electron_mobility format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electron_mobility_t{}) == "1 [m^2/(V s)]");
}
TEST_CASE("electron_mobility quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::electron_mobility) == "1 [m^2/(V s)]");
}
TEST_CASE("electron_mobility type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::electron_mobility)>, mitama::quantity_t<std::decay_t<decltype(kilogram<-1>*second<2>*ampere<1>)>>>);
}
