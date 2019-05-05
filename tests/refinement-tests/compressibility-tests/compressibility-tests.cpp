#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/compressibility.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("compressibility refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::compressibility_r> |= quantity_t<si::compressibility_t>{}) == quantity_t<si::compressibility_t>{});
}

