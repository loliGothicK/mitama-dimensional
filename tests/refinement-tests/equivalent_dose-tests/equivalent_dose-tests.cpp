#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/equivalent_dose.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("equivalent_dose refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::equivalent_dose_r> |= quantity_t<si::sievert_t>{}) == quantity_t<si::sievert_t>{});
}

