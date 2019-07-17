#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/refinement.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;

TEST_CASE("accepts refinement test", "[quantity][refinement]") {
  REQUIRE((mitama::accepts<length_r> |= quantity_t<systems::si::meter_t>{}) == quantity_t<systems::si::meter_t>{});
  REQUIRE((mitama::accepts<mass_r> |= quantity_t<systems::si::kilogram_t>{}) == quantity_t<systems::si::kilogram_t>{});
  REQUIRE((mitama::accepts<time_r> |= quantity_t<systems::si::second_t>{}) == quantity_t<systems::si::second_t>{});
  REQUIRE((mitama::accepts<current_r> |= quantity_t<systems::si::ampere_t>{}) == quantity_t<systems::si::ampere_t>{});
  REQUIRE((mitama::accepts<thermo_r> |= quantity_t<systems::si::kelvin_t>{}) == quantity_t<systems::si::kelvin_t>{});
  REQUIRE((mitama::accepts<amount_r> |= quantity_t<systems::si::mol_t>{}) == quantity_t<systems::si::mol_t>{});
  REQUIRE((mitama::accepts<luminous_r> |= quantity_t<systems::si::candela_t>{}) == quantity_t<systems::si::candela_t>{});
}

TEST_CASE("rejects refinement test", "[quantity][refinement]") {
  REQUIRE(IS_INVALID_EXPR(mitama::rejects<DECLTYPE(0)> |= DECLVAL(1))(length_r, quantity_t<systems::si::meter_t>));
  REQUIRE(IS_INVALID_EXPR(mitama::rejects<DECLTYPE(0)> |= DECLVAL(1))(mass_r, quantity_t<systems::si::kilogram_t>));
  REQUIRE(IS_INVALID_EXPR(mitama::rejects<DECLTYPE(0)> |= DECLVAL(1))(time_r, quantity_t<systems::si::second_t>));
  REQUIRE(IS_INVALID_EXPR(mitama::rejects<DECLTYPE(0)> |= DECLVAL(1))(current_r, quantity_t<systems::si::ampere_t>));
  REQUIRE(IS_INVALID_EXPR(mitama::rejects<DECLTYPE(0)> |= DECLVAL(1))(thermo_r, quantity_t<systems::si::kelvin_t>));
  REQUIRE(IS_INVALID_EXPR(mitama::rejects<DECLTYPE(0)> |= DECLVAL(1))(amount_r, quantity_t<systems::si::mol_t>));
  REQUIRE(IS_INVALID_EXPR(mitama::rejects<DECLTYPE(0)> |= DECLVAL(1))(luminous_r, quantity_t<systems::si::candela_t>));
}

