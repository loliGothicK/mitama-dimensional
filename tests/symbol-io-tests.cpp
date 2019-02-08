// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <quantity.hpp>
#include <si/all.hpp>
#include <prefix.hpp>
#include <io.hpp>
#include <arithmetic.hpp>
#include <boost/format.hpp>
#include "test_util.hpp"

using namespace mitama;
inline auto fmt = [](auto const& a){ return (boost::format("%1%") % a).str(); };
using namespace std::literals;

template < class Prefix, class Unit, class = void >
struct test_c {
    inline static constexpr auto value = 1 | Prefix{} * Unit{};
    static std::string expexted() { return std::to_string(1) + " [" + std::string(prefix_<Prefix>::str) + std::string(symbol_<typename basis_<Unit>::template type<0>>::str) + "]";  }
};
template < class Prefix, class Unit >
struct test_c<Prefix, Unit, std::enable_if_t<std::is_same_v<typename basis_<Unit>::template type<0>, mass>>> {
    inline static constexpr auto value = 1 | Prefix{} * Unit{};
    static std::string expexted() { return std::to_string(1) + " [" + std::string(prefix_<std::ratio_multiply<Prefix, std::kilo>>::str) + std::string(symbol_<typename basis_<Unit>::template type<0>>::str) + "]";  }
};
TEST_CASE("prefix format tests",
          "[prefix]")
{
    REQUIRE( prefix_<std::pico>::str == "p"s);
    REQUIRE( prefix_<std::nano>::str == "n"s);
    REQUIRE( prefix_<std::micro>::str == "u"s);
    REQUIRE( prefix_<std::milli>::str == "m"s);
    REQUIRE( prefix_<std::centi>::str == "c"s);
    REQUIRE( prefix_<std::deci>::str == "d"s);
    REQUIRE( prefix_<std::deca>::str == "da"s);
    REQUIRE( prefix_<std::hecto>::str == "h"s);
    REQUIRE( prefix_<std::kilo>::str == "k"s);
    REQUIRE( prefix_<std::mega>::str == "M"s);
    REQUIRE( prefix_<std::giga>::str == "G"s);
    REQUIRE( prefix_<std::tera>::str == "T"s);
}

TEST_CASE("symbol format tests",
          "[symbol]")
{
    REQUIRE( symbol_<::mitama::length>::str == "m"s);
    REQUIRE( symbol_<electric_current>::str == "A"s);
    REQUIRE( symbol_<luminous_intensity>::str == "cd"s);
    REQUIRE( symbol_<thermodynamic_temperature>::str == "K"s);
    REQUIRE( symbol_<::mitama::mass>::str == "g"s);
    REQUIRE( symbol_<amount_of_substance>::str == "mol"s);
    REQUIRE( symbol_<::mitama::time>::str == "s"s);
}

TEMPLATE_TEST_CASE("meter_t format tests",
                   "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi, std::deci,
                   std::deca, std::hecto, std::kilo, std::mega, std::giga, std::tera)
{
    REQUIRE( fmt(test_c<TestType, meter_t>::value) == test_c<TestType, meter_t>::expexted() );
}

TEMPLATE_TEST_CASE("ampere_t format tests",
                   "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi, std::deci,
                   std::deca, std::hecto, std::kilo, std::mega, std::giga, std::tera)
{
    REQUIRE( fmt(test_c<TestType, ampere_t>::value) == test_c<TestType, ampere_t>::expexted() );
}

TEMPLATE_TEST_CASE("candela_t format tests",
                   "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi, std::deci,
                   std::deca, std::hecto, std::kilo, std::mega, std::giga, std::tera)
{
    REQUIRE( fmt(test_c<TestType, candela_t>::value) == test_c<TestType, candela_t>::expexted() );
}

TEMPLATE_TEST_CASE("kelvin_t format tests",
                   "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi, std::deci,
                   std::deca, std::hecto, std::kilo, std::mega, std::giga, std::tera)
{
    REQUIRE( fmt(test_c<TestType, kelvin_t>::value) == test_c<TestType, kelvin_t>::expexted() );
}

TEMPLATE_TEST_CASE("mol_t format tests",
                   "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi, std::deci,
                   std::deca, std::hecto, std::kilo, std::mega, std::giga, std::tera)
{
    REQUIRE( fmt(test_c<TestType, mol_t>::value) == test_c<TestType, mol_t>::expexted() );
}

TEMPLATE_TEST_CASE("second_t format tests",
                   "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi, std::deci,
                   std::deca, std::hecto, std::kilo, std::mega, std::giga, std::tera)
{
    REQUIRE( fmt(test_c<TestType, second_t>::value) == test_c<TestType, second_t>::expexted() );
}

TEST_CASE("kilogram_t format tests",
            "[quantity][symbol][prefix]")
{
    REQUIRE( fmt(1|mega*kilograms) == "1 [Gg]" );
    REQUIRE( fmt(1|kilo*kilograms) == "1 [Mg]" );
    REQUIRE( fmt(1|kilograms) == "1 [kg]" );
    REQUIRE( fmt(1|milli*kilograms) == "1 [g]" );
    REQUIRE( fmt(1|micro*kilograms) == "1 [mg]" );
}
