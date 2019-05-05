#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/volumetric_flow.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("volumetric_flow refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::volumetric_flow_r> |= quantity_t<si::volumetric_flow_t>{}) == quantity_t<si::volumetric_flow_t>{});
}

