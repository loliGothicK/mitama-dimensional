#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/molality.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("molality refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::molality_r> |= quantity_t<si::molality_t>{}) == quantity_t<si::molality_t>{});
}

