#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/electric_displacement_field.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("electric_displacement_field refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::electric_displacement_field_r> |= quantity_t<si::electric_displacement_field_t>{}) == quantity_t<si::electric_displacement_field_t>{});
}

