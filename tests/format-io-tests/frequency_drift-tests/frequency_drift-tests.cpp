#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/derived_units/frequency_drift.hpp>
#include "../format_io_common.hpp"

TEST_CASE("frequency_drift format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::frequency_drift_t{}) == "1 [Hz/s]");
}
TEST_CASE("frequency_drift quantifier format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | systems::si::frequency_drift) == "1 [Hz/s]");
}
TEST_CASE("frequency_drift type test", "[quantity][abbreviation]") {
  REQUIRE(mitama::is_same_dimensional_v<std::decay_t<decltype(1|systems::si::frequency_drift)>, mitama::quantity_t<std::decay_t<decltype(second<-2>)>>>);
}
