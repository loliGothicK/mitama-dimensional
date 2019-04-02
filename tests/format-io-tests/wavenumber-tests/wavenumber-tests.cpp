#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/wavenumber.hpp>
#include "../format_io_common.hpp"

TEST_CASE("wavenumber format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::wavenumber_t{}) == "1 [m^-1]");
}
TEST_CASE("wavenumber quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::wavenumber) == "1 [m^-1]");
}
TEST_CASE("wavenumber type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::wavenumber)>, mitama::quantity_t<std::decay_t<decltype(meter<-1>)>>>);
}
