#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/action.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("action refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::action_r> |= quantity_t<si::action_t>{}) == quantity_t<si::action_t>{});
}

