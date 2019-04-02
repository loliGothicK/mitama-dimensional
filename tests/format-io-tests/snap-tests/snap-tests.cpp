#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/snap.hpp>
#include "../format_io_common.hpp"

TEST_CASE("snap format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::snap_t{}) == "1 [m/s^4]");
}
TEST_CASE("snap quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::snap) == "1 [m/s^4]");
}
TEST_CASE("snap type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::snap)>, mitama::quantity_t<std::decay_t<decltype(meters/second<4>)>>>);
}
