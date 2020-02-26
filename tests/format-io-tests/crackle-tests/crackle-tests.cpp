#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/crackle.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("crackle format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::crackle_t{}) == "1 [m/s^5]");
}
TEST_CASE("crackle quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::crackle) == "1 [m/s^5]");
}
TEST_CASE("crackle type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::crackle)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meters/second<5>)>>>);
}
