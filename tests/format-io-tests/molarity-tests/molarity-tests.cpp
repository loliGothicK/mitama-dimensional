#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/molarity.hpp>
#include "../format_io_common.hpp"

TEST_CASE("molarity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molarity_t{}) == "1 [mol/m^3]");
}
TEST_CASE("molarity quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::molarity) == "1 [mol/m^3]");
}
TEST_CASE("molarity type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::molarity)>, mitama::quantity_t<std::decay_t<decltype(meter<-3>*mol<>)>>>);
}
