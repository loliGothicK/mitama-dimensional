#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/frequency_drift.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("frequency_drift refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::frequency_drift_r> |= quantity_t<si::frequency_drift_t>{}) == quantity_t<si::frequency_drift_t>{});
}

