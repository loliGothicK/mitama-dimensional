#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/magnetic_vector_potential.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("magnetic_vector_potential refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::magnetic_vector_potential_r> |= quantity_t<systems::si::magnetic_vector_potential_t>{}) == quantity_t<systems::si::magnetic_vector_potential_t>{});
}

