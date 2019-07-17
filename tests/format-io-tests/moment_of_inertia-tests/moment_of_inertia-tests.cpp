#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/moment_of_inertia.hpp>
#include "../format_io_common.hpp"

TEST_CASE("moment_of_inertia format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::moment_of_inertia_t{}) == "1 [kg m^2]");
}
TEST_CASE("moment_of_inertia quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::moment_of_inertia) == "1 [kg m^2]");
}
TEST_CASE("moment_of_inertia type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::moment_of_inertia)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*kilograms)>>>);
}
