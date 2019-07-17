#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/fuel_efficiency.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("fuel_efficiency refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::fuel_efficiency_r> |= quantity_t<systems::si::fuel_efficiency_t>{}) == quantity_t<systems::si::fuel_efficiency_t>{});
}

