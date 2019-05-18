# Delta type

Delta type is a type to represent the difference of dimensional quantity.

Typical use case is temperature difference.

Assigning `quantity<kelvin_t>` to `quantity <degree_celsius_t>` will convert that value.
However, `delta<quantity<kelvin_t >>` is a type representing temperature difference, so it is assigned without conversion.


```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/kelvin.hpp>
#include <dimensional/systems/nonsi/degree_celsius.hpp>
#include <dimensional/delta.hpp>
#include <dimensional/arithmetic.hpp>

int main() {
    using namespace mitama;
    namespace si = systems::si;
    namespace nonsi = systems::nonsi;

    quantity<nonsi::degree_celsius_t> c = 100;
    // Calculated without unit conversion
    // because it is a temperature difference.
    // 20 - 10 = 10 delta kelvin <=> 10 delta degree celcius
    quantity<nonsi::degree_celsius_t> res = c + delta( (20|si::kelvins) - (10|si::kelvins) ); 
}
// end example
```