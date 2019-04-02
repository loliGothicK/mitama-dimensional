#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/electric_current_density.hpp>
#include "../format_io_common.hpp"

TEST_CASE("electric_current_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::electric_current_density_t{}) == "1 [A/m^2]");
}
TEST_CASE("electric_current_density quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::electric_current_density) == "1 [A/m^2]");
}
TEST_CASE("electric_current_density type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::electric_current_density)>, mitama::quantity_t<std::decay_t<decltype(meter<-2>*ampere<>)>>>);
}
