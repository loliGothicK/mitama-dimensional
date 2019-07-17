#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/systems/si/derived_units/wavenumber.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("wavenumber refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<systems::si::wavenumber_r> |= quantity_t<systems::si::wavenumber_t>{}) == quantity_t<systems::si::wavenumber_t>{});
}

