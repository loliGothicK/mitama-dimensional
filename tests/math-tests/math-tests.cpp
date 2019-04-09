// main is provided in tests-main.cpp
#include <catch2/catch.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/prefix.hpp>
#include <random>
#include <test_util.hpp>
#include <dimensional/expr.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/math/all.hpp>
#include <dimensional/derived_units/angle.hpp>

using namespace mitama;
using Catch::Detail::Approx;
using namespace mitama::si;
using namespace mitama::nonsi;

TEMPLATE_TEST_CASE("abs tests",
                   "[quantity][abs][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-10000, 10000)
            .take(1000)
            .required([](auto value){
                quantity<TestType, int> v = value;
                return abs(v).get() == std::abs(value);
            }));
}

TEMPLATE_TEST_CASE("min tests",
                   "[quantity][min][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-10000, 10000)
            .take(1000)
            .template required<2>([](auto v1, auto v2){
                quantity<TestType, int> q1 = v1;
                quantity<TestType, int> q2 = v2;
                return min(q1, q2).get() == std::min({v1, v2});
            }));
}

TEMPLATE_TEST_CASE("max tests",
                   "[quantity][max][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-10000, 10000)
            .take(1000)
            .template required<2>([](auto v1, auto v2){
                quantity<TestType, int> q1 = v1;
                quantity<TestType, int> q2 = v2;
                return max(q1, q2).get() == std::max({v1, v2});
            }));
}

TEMPLATE_TEST_CASE("pow tests",
                   "[quantity][pow][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-10000, 10000)
            .take(1000)
            .required([](auto value){
                quantity<TestType, int> v = value;
                return mitama::pow<2>(v) == v * v;
            }));
    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-10000, 10000)
            .take(1000)
            .required([](auto value){
                quantity<TestType> v = value;
                return mitama::pow<-1>(v).get() == Approx(std::pow(value, -1));
            }));
    REQUIRE(
        test_util::RandomGenerator<int>::uniform(0, 10000)
            .take(1000)
            .required([](auto value){
                quantity<TestType> v = value;
                return mitama::pow<std::ratio<3, 2>>(v).get() == Approx(std::pow(value, 3.l/2.l));
            }));
}

TEMPLATE_TEST_CASE("square tests",
                   "[quantity][square][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-10000, 10000)
            .take(1000)
            .required([](auto value){
                quantity<TestType, int> v = value;
                return square(v) == v * v;
            }));
}

TEMPLATE_TEST_CASE("cubic tests",
                   "[quantity][cubic][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-10000, 10000)
            .take(1000)
            .required([](auto value){
                quantity<TestType, int> v = value;
                return cubic(v) == v * v * v;
            }));
}

TEMPLATE_TEST_CASE("sqrt tests",
                   "[quantity][sqrt][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(0, 10000)
            .take(1000)
            .required([](auto value){
                quantity<TestType> v = value;
                return sqrt(v).get() == Approx(std::sqrt(value));
            }));
}

TEMPLATE_TEST_CASE("cbrt tests",
                   "[quantity][cbrt][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<int>::uniform(0, 10000)
            .take(1000)
            .required([](auto value){
                quantity<TestType> v = value;
                return cbrt(v).get() == Approx(std::cbrt(value));
            }));
}

TEMPLATE_TEST_CASE("ceil tests",
                   "[quantity][ceil][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return ceil(v) == quantity<TestType>(std::ceil(value));
            }));
}

TEMPLATE_TEST_CASE("floor tests",
                   "[quantity][floor][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return floor(v) == quantity<TestType>(std::floor(value));
            }));
}

TEMPLATE_TEST_CASE("trunc tests",
                   "[quantity][trunc][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return trunc(v) == quantity<TestType>(std::trunc(value));
            }));
}

TEMPLATE_TEST_CASE("round tests",
                   "[quantity][round][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return round(v) == quantity<TestType>(std::round(value));
            }));
}

TEMPLATE_TEST_CASE("lround tests",
                   "[quantity][lround][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return lround(v) == quantity<TestType, long>(std::lround(value));
            }));
}

TEMPLATE_TEST_CASE("llround tests",
                   "[quantity][llround][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return llround(v) == quantity<TestType, long long>(std::llround(value));
            }));
}

TEMPLATE_TEST_CASE("nearbyint tests",
                   "[quantity][nearbyint][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return nearbyint(v) == quantity<TestType>(std::nearbyint(value));
            }));
}

TEMPLATE_TEST_CASE("rint tests",
                   "[quantity][rint][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return rint(v) == quantity<TestType>(std::rint(value));
            }));
}

TEMPLATE_TEST_CASE("lrint tests",
                   "[quantity][lrint][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return lrint(v) == quantity<TestType, long>(std::lrint(value));
            }));
}

TEMPLATE_TEST_CASE("llrint tests",
                   "[quantity][llrint][math]",
                   second_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t)
{
    using namespace Catch::literals;

    REQUIRE(
        test_util::RandomGenerator<double>::uniform(-100, 100)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return llrint(v) == quantity<TestType, long long>(std::llrint(value));
            }));
}


TEST_CASE("sin for radian", "[math],[quantity],[sin]")
{
    quantity<radian_t> rad = 3 | radian;
    REQUIRE(sin(rad) == std::sin(3));
}

TEMPLATE_TEST_CASE("sin with arg not radian", "[math],[quantity],[sin]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(sin(DECLVAL(0)))(quantity<TestType>));
}

TEST_CASE("cos for radian", "[math],[quantity],[cos]")
{
    quantity<radian_t> rad = 3 | radian;
    REQUIRE(cos(rad) == std::cos(3));
}

TEMPLATE_TEST_CASE("cos with arg not radian", "[math],[quantity],[cos]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(cos(DECLVAL(0)))(quantity<TestType>));
}

TEST_CASE("tan for radian", "[math],[quantity],[tan]")
{
    quantity<radian_t> rad = 3 | radian;
    REQUIRE(tan(rad) == std::tan(3));
}

TEMPLATE_TEST_CASE("tan with arg not radian", "[math],[quantity],[tan]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(tan(DECLVAL(0)))(quantity<TestType>));
}

TEST_CASE("asin", "[math],[quantity],[asin]")
{
    quantity<radian_t> rad = std::asin(1) | radian;
    REQUIRE(mitama::asin(1) == rad);
}

TEST_CASE("acos", "[math],[quantity],[acos]")
{
    quantity<radian_t> rad = std::acos(1) | radian;
    REQUIRE(mitama::acos(1) == rad);
}

TEST_CASE("atan", "[math],[quantity],[atan]")
{
    quantity<radian_t> rad = std::atan(1) | radian;
    REQUIRE(mitama::atan(1) == rad);
}

TEMPLATE_TEST_CASE("asin with si", "[math],[quantity],[asin]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(mitama::asin(DECLVAL(0)))(quantity<TestType>));
}

TEMPLATE_TEST_CASE("acos with si", "[math],[quantity],[acos]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(mitama::acos(DECLVAL(0)))(quantity<TestType>));
}

TEMPLATE_TEST_CASE("atan with si", "[math],[quantity],[atan]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    REQUIRE(IS_INVALID_EXPR(mitama::atan(DECLVAL(0)))(quantity<TestType>));
}

TEMPLATE_TEST_CASE("fmod with dimensionless denominator", "[math],[quantity],[fmod]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(fmod(quantity<TestType>(5.0), 2.0).get() == 1.0_a);
    REQUIRE(fmod(quantity<TestType>(6.0), 4.0).get() == 2.0_a);
    REQUIRE(fmod(quantity<TestType>(6.3), 3.0).get() == 0.3_a);
    REQUIRE(fmod(quantity<TestType>(6.3), -3.0).get() == 0.3_a);
    REQUIRE(fmod(quantity<TestType>(-6.3), 3.0).get() == -0.3_a);
    REQUIRE(fmod(quantity<TestType>(-6.3), -3.0).get() == -0.3_a);
    REQUIRE(fmod(quantity<TestType>(6.3), 3.15).get() == 0.0_a);
    REQUIRE(fmod(quantity<TestType>(6.0), 2.0).get() == 0.0_a);
}

TEMPLATE_TEST_CASE("fmod with dimensional quantity denominator", "[math],[quantity],[fmod]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(fmod(quantity<TestType>(5.0), quantity<TestType>(2.0)).get() == 1.0_a);
    REQUIRE(fmod(quantity<TestType>(6.0), quantity<TestType>(4.0)).get() == 2.0_a);
    REQUIRE(fmod(quantity<TestType>(6.3), quantity<TestType>(3.0)).get() == 0.3_a);
    REQUIRE(fmod(quantity<TestType>(6.3), quantity<TestType>(-3.0)).get() == 0.3_a);
    REQUIRE(fmod(quantity<TestType>(-6.3), quantity<TestType>(3.0)).get() == -0.3_a);
    REQUIRE(fmod(quantity<TestType>(-6.3), quantity<TestType>(-3.0)).get() == -0.3_a);
    REQUIRE(fmod(quantity<TestType>(6.3), quantity<TestType>(3.15)).get() == 0.0_a);
    REQUIRE(fmod(quantity<TestType>(6.0), quantity<TestType>(2.0)).get() == 0.0_a);
}

TEMPLATE_TEST_CASE("remainder with dimensionless denominator", "[math],[quantity],[remainder]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(remainder(quantity<TestType>(5), 2).get() == 1.0_a);
    REQUIRE(remainder(quantity<TestType>(6), 4).get() == -2.0_a);
    REQUIRE(remainder(quantity<TestType>(6.3), 3).get() == 0.3_a);
    REQUIRE(remainder(quantity<TestType>(6.3), -3).get() == 0.3_a);
    REQUIRE(remainder(quantity<TestType>(-6.3), 3).get() == -0.3_a);
    REQUIRE(remainder(quantity<TestType>(-6.3), -3).get() == -0.3_a);
    REQUIRE(remainder(quantity<TestType>(6.3), 3.15).get() == 0.0_a);
    REQUIRE(remainder(quantity<TestType>(6), 2).get() == 0.0_a);
}

TEMPLATE_TEST_CASE("remainder with dimensional quantity denominator", "[math],[quantity],[remainder]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(remainder(quantity<TestType>(5), quantity<TestType>(2)).get() == 1.0_a);
    REQUIRE(remainder(quantity<TestType>(6), quantity<TestType>(4)).get() == -2.0_a);
    REQUIRE(remainder(quantity<TestType>(6.3), quantity<TestType>(3)).get() == 0.3_a);
    REQUIRE(remainder(quantity<TestType>(6.3), quantity<TestType>(-3)).get() == 0.3_a);
    REQUIRE(remainder(quantity<TestType>(-6.3), quantity<TestType>(3)).get() == -0.3_a);
    REQUIRE(remainder(quantity<TestType>(-6.3), quantity<TestType>(-3)).get() == -0.3_a);
    REQUIRE(remainder(quantity<TestType>(6.3), quantity<TestType>(3.15)).get() == 0.0_a);
    REQUIRE(remainder(quantity<TestType>(6), quantity<TestType>(2)).get() == 0.0_a);
}

TEMPLATE_TEST_CASE("dim", "[math],[quantity],[remainder]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(dim(quantity<TestType>(5), quantity<TestType>(2)).get() == 3.0_a);
    REQUIRE(dim(quantity<TestType>(6), quantity<TestType>(4)).get() == 2.0_a);
    REQUIRE(dim(quantity<TestType>(1), quantity<TestType>(3)).get() == +0);
    REQUIRE(dim(quantity<TestType>(-4), quantity<TestType>(-3)).get() == +0);
}

TEMPLATE_TEST_CASE("log", "[math],[quantity],[log]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(
        test_util::RandomGenerator<double>::uniform(1, 10E10)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return log(v) == quantity<dimless_t>(std::log(value));
            }));
}

TEMPLATE_TEST_CASE("log2", "[math],[quantity],[log]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(
        test_util::RandomGenerator<double>::uniform(1, 10E10)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return log2(v) == quantity<dimless_t>(std::log2(value));
            }));
}

TEMPLATE_TEST_CASE("log10", "[math],[quantity],[log]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(
        test_util::RandomGenerator<double>::uniform(1, 10E10)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return log10(v) == quantity<dimless_t>(std::log10(value));
            }));
}

TEMPLATE_TEST_CASE("log1p", "[math],[quantity],[log]",
                   radian_t, meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    using namespace Catch::literals;
    REQUIRE(
        test_util::RandomGenerator<double>::uniform(1, 10E10)
            .take(100000)
            .required([](auto value){
                quantity<TestType> v = value;
                return log1p(v) == quantity<dimless_t>(std::log1p(value));
            }));
}
