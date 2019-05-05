#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/magnetization.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("magnetization refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::magnetization_r> |= quantity_t<si::magnetization_t>{}) == quantity_t<si::magnetization_t>{});
}

