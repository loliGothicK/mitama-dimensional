#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/derived_units/torque.hpp>
#include "../format_io_common.hpp"

TEST_CASE("torque format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::torque_t{}) == "1 [N·m]");
}
TEST_CASE("torque quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | si::torque) == "1 [N·m]");
}
TEST_CASE("torque type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|si::torque)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*kilograms*second<-2>)>>>);
}
