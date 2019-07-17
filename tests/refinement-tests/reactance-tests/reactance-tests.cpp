#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/reactance.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("reactance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::reactance_r> |= quantity_t<systems::si::reactance_t>{}) == quantity_t<systems::si::reactance_t>{});
}

