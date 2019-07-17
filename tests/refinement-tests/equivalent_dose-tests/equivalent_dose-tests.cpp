#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/equivalent_dose.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("equivalent_dose refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::equivalent_dose_r> |= quantity_t<systems::si::sievert_t>{}) == quantity_t<systems::si::sievert_t>{});
}

