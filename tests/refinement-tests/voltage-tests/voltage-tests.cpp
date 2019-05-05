#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/derived_units/voltage.hpp>
#include <dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;

TEST_CASE("voltage refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::exact<si::voltage_r> |= quantity_t<si::voltage_t>{}) == quantity_t<si::voltage_t>{});
}

