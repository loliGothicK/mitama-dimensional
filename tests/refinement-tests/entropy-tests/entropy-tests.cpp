#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/entropy.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("entropy refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::entropy_r> |= quantity_t<si::entropy_t>{}) == quantity_t<si::entropy_t>{});
}

