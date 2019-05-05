#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/volume.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("volume refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::volume_r> |= quantity_t<si::volume_t>{}) == quantity_t<si::volume_t>{});
}

