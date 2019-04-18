
# Dimensional quantifiers
-----------------------

Dimensional quantifiers are defined as constexpr variables (templates) of dimensional_t (see [3.2 dimensional_t]() in detail).

For example,

```cpp
inline constexpr meter_t meters;

template < std::intmax_t N = 1 >
inline constexpr powered_t<meter_t, N> meter;
```

If you do not specify the exponent (=1), use the plural dimension quantifiers, and if you specify it, use the singular dimension quantifiers with non-type template parameter.

## pipe operator overload
----------------------------

Pipe operators are provided to attach units to values.

It is allowed to convert values into quantities by piping values to dimensional quantifiers.

**example**

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    // Template argument deduction for class templates
    quantity_t mass = 3 | si::kilograms; // 3 [kg]

    quantity_t time = 1.66 | si::seconds; // 1.66 [s]

    quantity_t volume = 4 | si::meter<3>; // 4 [m^3]
}
// end example
```

## multiplication and division operators
----------------------------

Multiplication and division operators for dimensional quantifiers are provided to make derived units.

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    // Template argument deduction for class templates
    quantity_t density = 3 | si::kilograms / si::meter<3>; // 3 [kg / m^3]

    quantity_t speed = 1.2 | si::meters / si::seconds; // 1.2 [m / s]

    quantity_t accel = 4 | si::meters * si::second<-2>; // 4 [s / m^2]
}
// end example
```
