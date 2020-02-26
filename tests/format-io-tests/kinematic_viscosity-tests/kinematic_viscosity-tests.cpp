#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/kinematic_viscosity.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("kinematic_viscosity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::kinematic_viscosity_t{}) == "1 [m^2/s]");
}
TEST_CASE("kinematic_viscosity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::kinematic_viscosity) == "1 [m^2/s]");
}
TEST_CASE("kinematic_viscosity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::kinematic_viscosity)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<2>*second<-1>)>>>);
}
