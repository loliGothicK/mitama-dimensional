## Expression templates

Addition of celsius temperature and absolute temperature is possible by performing a conversion.
However, there is a problem.
Compiler do not know if it would be nice if the result could be adjusted to either unit.

In order to solve this problem, an expression template is used.
An expression template creates a temporary object and delays unit calculation until assignment.
Determine how to perform unit conversion from the dimension of assignment destination.

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/nonsi_units/degree_celsius.hpp>
#include <dimensional/expr.hpp>

int main(){
    namespace si = mitama::si;
    namespace nonsi = mitama::nonsi;
    using mitama::quantity, mitama::as_expr;

    quantity<decltype(si::kelvin<> / si::second<>)>
        x = as_expr(1|si::kelvins) / (2|si::seconds) +
            as_expr(2|nonsi::degree_celsius) / (2|si::seconds);
    // x = 137.575 [K/s]

    quantity<decltype(si::kelvin<> / si::second<>)>
        y = (as_expr(11|si::kelvins) - as_expr(1|si::kelvins)) / (2|si::seconds) + 
            (as_expr(21|nonsi::degree_celsius) - as_expr(1|nonsi::degree_celsius)) / (2|si::seconds);
    // x = 15 [K/s]
}
// end example
```

