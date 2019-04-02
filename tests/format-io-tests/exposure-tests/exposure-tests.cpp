#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/exposure.hpp>
#include "../format_io_common.hpp"

TEST_CASE("exposure format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::exposure_t{}) == "1 [C/kg]");
}
TEST_CASE("exposure quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::exposure) == "1 [C/kg]");
}
TEST_CASE("exposure type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::exposure)>, mitama::quantity_t<std::decay_t<decltype(kilogram<-1>*second<>*ampere<>)>>>);
}
