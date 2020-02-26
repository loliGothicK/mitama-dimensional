#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/dynamic_viscosity.hpp>
#include <mitama/dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("dynamic_viscosity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::dynamic_viscosity_t{}) == "1 [Pa s]");
}
TEST_CASE("dynamic_viscosity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::dynamic_viscosity) == "1 [Pa s]");
}
TEST_CASE("dynamic_viscosity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::dynamic_viscosity)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<-1>*kilograms*second<-1>)>>>);
}
