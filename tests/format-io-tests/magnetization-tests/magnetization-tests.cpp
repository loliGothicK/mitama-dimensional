#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/magnetization.hpp>
#include "../format_io_common.hpp"

TEST_CASE("magnetization format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::magnetization_t{}) == "1 [A/m]");
}
TEST_CASE("magnetization quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::magnetization) == "1 [A/m]");
}
TEST_CASE("magnetization type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::magnetization)>, mitama::quantity_t<std::decay_t<decltype(meter<-1>*ampere<>)>>>);
}
