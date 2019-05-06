#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/absorbed_dose.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("absorbed_dose refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::absorbed_dose_r> |= quantity_t<si::absorbed_dose_t>{}) == quantity_t<si::absorbed_dose_t>{});
}

