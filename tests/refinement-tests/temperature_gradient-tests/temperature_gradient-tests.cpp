#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/temperature_gradient.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("temperature_gradient refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::temperature_gradient_r> |= quantity_t<si::temperature_gradient_t>{}) == quantity_t<si::temperature_gradient_t>{});
}

