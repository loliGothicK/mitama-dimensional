#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/absorbed_dose_rate.hpp>
#include "../format_io_common.hpp"

TEST_CASE("absorbed_dose_rate format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::absorbed_dose_rate_t{}) == "1 [Gy/s]");
}
TEST_CASE("absorbed_dose_rate quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::absorbed_dose_rate) == "1 [Gy/s]");
}
TEST_CASE("absorbed_dose_rate type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::absorbed_dose_rate)>, mitama::quantity_t<std::decay_t<decltype(meter<2>*second<-3>)>>>);
}
