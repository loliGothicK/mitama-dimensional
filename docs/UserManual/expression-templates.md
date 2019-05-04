# Dimensional refinement

>"I mean, it's sort of exciting, isn't it, breaking the rules?" — Hermione Granger, Harry Potter and the Order of the Phoenix

----------------------

## Expression templates

Addition of celsious temperature and absolute temperature is possible by performing a conversion.
However, there is a problem.
Compiler do not know if it would be nice if the result could be adjusted to either unit.

In order to solve this problem, an expression template is used.
An expression template creates a temporary object and delays unit conversion until substitution.
Determine how to perform unit conversion from the dimension of substitution destination.

```cpp
// begin example
#include <quantity.hpp>
#include <nonsi_units/degree_celsius.hpp>
#include <expr.hpp>

int main(){
    using namespace Catch::literals;
    quantity<decltype(kelvin<>/second<>)>
        x = as_expr(1|kelvins) / (2|seconds) +
            as_expr(2|degree_celsius) / (2|seconds);
    // x = 137.575 [K/s]

    quantity<decltype(kelvin<>/second<>)>
        y = (as_expr(11|kelvins) - as_expr(1|kelvins)) / (2|seconds) + 
            (as_expr(21|degree_celsius) - as_expr(1|degree_celsius)) / (2|seconds);
    // x = 15 [K/s]
}
// end example
```

