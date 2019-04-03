#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/compressibility.hpp>
#include "../format_io_common.hpp"

TEST_CASE("compressibility format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::compressibility_t{}) == "1 [Pa^-1]");
}
TEST_CASE("compressibility quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::compressibility) == "1 [Pa^-1]");
}
TEST_CASE("compressibility type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::compressibility)>, mitama::quantity_t<std::decay_t<decltype(meters*kilogram<-1>*second<2>)>>>);
}