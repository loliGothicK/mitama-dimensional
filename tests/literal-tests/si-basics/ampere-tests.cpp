// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/systems/si/quantity.hpp>
#include <dimensional/systems/si/prefix.hpp>
#include <dimensional/arithmetic.hpp>
#include <test_util.hpp>

namespace si = mitama::systems::si;

#include <dimensional/systems/si/literals/ampere_literals.hpp>

TEST_CASE("ampere literals",
          "[quantity][literals]")
{
    using namespace mitama::literals;
    REQUIRE(std::is_same_v<
        decltype(1.0_A),
        si::quantity_t<si::ampere_t, long double>
    >);
}

TEST_CASE("milli-ampere literals",
          "[quantity][literals]")
{
    using namespace mitama::literals;
    REQUIRE(std::is_same_v<
        decltype(1.0_mA),
        si::quantity_t<si::milliampere_t, long double>
    >);
}

TEST_CASE("micro-ampere literals",
          "[quantity][literals]")
{
    using namespace mitama::literals;
    REQUIRE(std::is_same_v<
        decltype(1.0_μA),
        si::quantity_t<si::microampere_t, long double>
    >);
}

TEST_CASE("kilo-ampere literals",
          "[quantity][literals]")
{
    using namespace mitama::literals;
    REQUIRE(std::is_same_v<
        decltype(1.0_kA),
        si::quantity_t<si::kiloampere_t, long double>
    >);
}

TEST_CASE("mega-ampere literals",
          "[quantity][literals]")
{
    using namespace mitama::literals;
    REQUIRE(std::is_same_v<
        decltype(1.0_MA),
        si::quantity_t<si::megaampere_t, long double>
    >);
}
