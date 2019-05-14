#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/pop.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("pop refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::pop_r> |= quantity_t<si::pop_t>{}) == quantity_t<si::pop_t>{});
}
