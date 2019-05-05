#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/radiance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("radiance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::radiance_r> |= quantity_t<si::radiance_t>{}) == quantity_t<si::radiance_t>{});
}

