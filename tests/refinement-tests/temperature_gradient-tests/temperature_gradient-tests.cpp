#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/temperature_gradient.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("temperature_gradient refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::temperature_gradient_r> |= quantity_t<systems::si::temperature_gradient_t>{}) == quantity_t<systems::si::temperature_gradient_t>{});
}

