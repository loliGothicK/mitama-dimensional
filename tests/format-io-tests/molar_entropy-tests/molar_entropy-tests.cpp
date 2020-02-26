#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/molar_entropy.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("molar_entropy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_entropy_t{}) == "1 [J/(K mol)]");
}
TEST_CASE("molar_entropy quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molar_entropy) == "1 [J/(K mol)]");
}
TEST_CASE("molar_entropy type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::molar_entropy)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<2>*kilograms*second<-2>*kelvin<-1>*mol<-1>)>>>);
}
