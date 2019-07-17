#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/angular_momentum.hpp>
#include "../format_io_common.hpp"

TEST_CASE("angular_momentum format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::angular_momentum_t{}) == "1 [N m s]");
}
TEST_CASE("angular_momentum quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::angular_momentum) == "1 [N m s]");
}
TEST_CASE("angular_momentum type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::angular_momentum)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*kilograms*second<-1>)>>>);
}
