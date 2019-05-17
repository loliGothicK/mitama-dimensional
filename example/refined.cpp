#include <dimensional/quantity.hpp>
#include <dimensional/static_quantity.hpp>
#include <dimensional/systems/si/meter.hpp>
#include <dimensional/io.hpp>
#include <iostream>

template < auto Arg >
struct is_even: std::bool_constant<Arg % 2 == 0> {};

template < auto Arg >
struct is_odd: std::bool_constant<Arg % 2 == 1> {};

int main(){
    namespace si = mitama::systems::si;
    using mitama::static_quantity, mitama::refined, mitama::quantity_t;
    using namespace mitama::literals::static_quantity_literals;

    constexpr refined<is_even, quantity_t<si::meter_t, int>> refined_length = 2_m;
    std::cout << refined_length.get() << std::endl;

    // It is a compilation error because the predicate `is_even` is not satisfied
    // constexpr refined<is_even, quantity_t<si::meter_t, int>> error_ = 3_m;

    constexpr refined<is_odd, quantity_t<si::gram_t, int>> refined_mass = 1_kg;

    constexpr quantity_t mass = refined_mass;

    std::cout << mass << std::endl;
}
