#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/curvature.hpp>
#include "../format_io_common.hpp"

TEST_CASE("curvature format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::curvature_t{}) == "1 [m^-1]");
}
TEST_CASE("curvature quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::curvature) == "1 [m^-1]");
}
TEST_CASE("curvature type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::curvature)>, mitama::quantity_t<std::decay_t<decltype(meter<-1>)>>>);
}
