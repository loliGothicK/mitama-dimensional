#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/exposure.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("exposure refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::exposure_r> |= quantity_t<si::exposure_t>{}) == quantity_t<si::exposure_t>{});
}

