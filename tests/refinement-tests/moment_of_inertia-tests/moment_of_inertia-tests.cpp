#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/moment_of_inertia.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("moment_of_inertia refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<si::moment_of_inertia_r> |= quantity_t<si::moment_of_inertia_t>{}) == quantity_t<si::moment_of_inertia_t>{});
}

