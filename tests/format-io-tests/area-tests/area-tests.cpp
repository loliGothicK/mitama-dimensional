#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/area.hpp>
#include "../format_io_common.hpp"

TEST_CASE("area format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(exact<area_r> |= 1 | si::area_t{}) == "1 [m^2]");
}
TEST_CASE("area quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::area) == "1 [m^2]");
}
TEST_CASE("area type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::area)>, mitama::quantity_t<std::decay_t<decltype(meter<2>)>>>);
}
