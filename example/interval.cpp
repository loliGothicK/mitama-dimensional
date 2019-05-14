#include "../include/dimensional/quantity.hpp"
#include "../include/dimensional/arithmetic.hpp"
#include "../include/dimensional/systems/si/all.hpp"
#include "../include/dimensional/io.hpp"
#include "../cranberries/interval.hpp"

int main() {
    using namespace mitama;
    namespace si = mitama::systems::si;
    using cranberries::interval;

    interval<double> a (1, 2);
    auto b = a|si::meters;
    std::cout << b + b << std::endl;
    std::cout << b - b << std::endl;
    std::cout << b * b << std::endl;
    std::cout << b / b << std::endl;
}