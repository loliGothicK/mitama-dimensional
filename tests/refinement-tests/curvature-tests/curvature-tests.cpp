#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/curvature.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("curvature refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::curvature_r> |= quantity_t<si::curvature_t>{}) == quantity_t<si::curvature_t>{});
}

