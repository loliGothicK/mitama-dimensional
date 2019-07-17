#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/mass_flow_rate.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("mass_flow_rate refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::mass_flow_rate_r> |= quantity_t<systems::si::mass_flow_rate_t>{}) == quantity_t<systems::si::mass_flow_rate_t>{});
}

