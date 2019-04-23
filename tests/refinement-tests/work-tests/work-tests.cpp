#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/work.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("work refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::refined<si::work_r> |= quantity_t<si::work_t>{}) == quantity_t<si::work_t>{});
}

