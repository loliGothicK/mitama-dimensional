#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/magnetomotive_force.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("magnetomotive_force refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::magnetomotive_force_r> |= quantity_t<si::magnetomotive_force_t>{}) == quantity_t<si::magnetomotive_force_t>{});
}

