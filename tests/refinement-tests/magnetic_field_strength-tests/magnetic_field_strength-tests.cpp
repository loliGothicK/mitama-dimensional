#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/magnetic_field_strength.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("magnetic_field_strength refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::magnetic_field_strength_r> |= quantity_t<si::magnetic_field_strength_t>{}) == quantity_t<si::magnetic_field_strength_t>{});
}

