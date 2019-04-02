#include "../config.hpp"
TEMPLATE_TEST_CASE("meter_t addition negative tests",
                   "[quantity][arithmetic]",
                   meter_t, ampere_t, candela_t, kelvin_t, kilogram_t, mol_t, second_t)
{
    constexpr TestType q{};
    REQUIRE(
        test_util::RandomGenerator<int>::uniform(-std::numeric_limits<int>::max()/3, std::numeric_limits<int>::max()/3)
            .take(1'000'000)
            .template required<2>([&](auto a, auto b){
                return std::pair{((a|q) + (b|q)).get(), a + b};
            }));
}

