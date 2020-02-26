#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/systems/si/derived_units/diffusion_coefficient.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("diffusion_coefficient format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::diffusion_coefficient_t{}) == "1 [m^2/s]");
}
TEST_CASE("diffusion_coefficient quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::diffusion_coefficient) == "1 [m^2/s]");
}
TEST_CASE("diffusion_coefficient type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::diffusion_coefficient)>, mitama::systems::si::quantity_t<std::decay_t<decltype(meter<2>*second<-1>)>>>);
}
