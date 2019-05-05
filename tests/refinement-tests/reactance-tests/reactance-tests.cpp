#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/reactance.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("reactance refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::reactance_r> |= quantity_t<si::reactance_t>{}) == quantity_t<si::reactance_t>{});
}

