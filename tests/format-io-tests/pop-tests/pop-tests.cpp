#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/pop.hpp>
#include "../format_io_common.hpp"

TEST_CASE("pop format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::pop_t{}) == "1 [m/s^6]");
}
TEST_CASE("pop quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::pop) == "1 [m/s^6]");
}
TEST_CASE("pop type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::pop)>, mitama::quantity_t<std::decay_t<decltype(meters/second<6>)>>>);
}
