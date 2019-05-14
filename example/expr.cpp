#include <dimensional/quantity.hpp>
#include <dimensional/systems/nonsi/degree_celsius.hpp>
#include <dimensional/expr.hpp>
#include <dimensional/static_quantity.hpp>
#include <iostream>

int main(){
    namespace si = mitama::systems::si;
    namespace nonsi = mitama::systems::nonsi;
    using mitama::static_quantity;

    constexpr auto sq = mitama::pow<2>(static_quantity<si::meter_t, 1> + static_quantity<si::millimeter_t, 1>);
    std::cout << std::decay_t<decltype(sq)>::value << std::endl;
}
