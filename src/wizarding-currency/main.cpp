#include <dimensional/quantity.hpp>
#include "wizarding_currency.hpp"
#include <iostream>

int main() {
    using mitama::quantity;
    using namespace wizarding;

    quantity<galleon_t> g = 1;
    quantity<sickle_t> s = 1|galleon;
    quantity<knut_t> k = 1|sickle;

    std::cout << g << std::endl; // 1 [galleons]
    std::cout << s << std::endl; // 17 [sickles]
    std::cout << k << std::endl; // 29 [knuts]
}