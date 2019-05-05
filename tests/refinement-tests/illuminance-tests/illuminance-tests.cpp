#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/illuminance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("illuminance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::illuminance_r> |= quantity_t<si::illuminance_t>{}) == quantity_t<si::illuminance_t>{});
}

