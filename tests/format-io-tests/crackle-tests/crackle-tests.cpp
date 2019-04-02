#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/crackle.hpp>
#include "../format_io_common.hpp"

TEST_CASE("crackle format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::crackle_t{}) == "1 [m/s^5]");
}
TEST_CASE("crackle quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::crackle) == "1 [m/s^5]");
}
TEST_CASE("crackle type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::crackle)>, mitama::quantity_t<std::decay_t<decltype(meters/second<5>)>>>);
}
