# mitama::quantity_t
------------------

Defined in header [`<dimensional/quantity.hpp>`]()

`quantity_t<Units, T>` is a class that represents a dimensional quantity of `Units` that has value type of `T`.

**definition**

```cpp
namespace mitama {
    template <
        class Units, // phantom type
        class T = double // underlying type
    >
    class quantity_t;

    template < class Units, class T = double >
    using quantity = quantity_t<Units, T>;
}
```


!!! Note
    If the second template argument is omitted, it will be of type `double`.


**example**

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    quantity_t<si::meter_t, int> len1 = 1; // 1 [m]
    quantity_t<si::meter_t, double> len2 = 1.45; // 1.45 [m]
}
// end example
```

## conversions
----------------------------

Conversion between different units is performed automatically.
Conversion between units with different dimensions will result in compilation errors.

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    quantity_t a = 3 | si::kilograms;
    quantity_t<si::gram_t, int> b = a; // 3000 [g]
    // quantity_t<si::meter_t, int> b = a; // compile error!
}
// end example
```

## arithmetic operators
----------------------------

Defined in header [`<dimensional/arithmetic.hpp>`]()

Let

- `q1` is a value with type of `quantity_t<D1, T1>`,
- `q2` is a value with type of `quantity_t<D2, T2>` and
- `v` is a value with type of `T3`.

And arithmetic operators listed bellow are defined:

| expression |                                             condition                                              |
| :--------: | :------------------------------------------------------------------------------------------------: |
| `q1 + q2`  | `D1` and `D2` has same dimension and `std::declval<T1>() + std::declval<T2>()` is valid expression |
| `q1 - q2`  | `D1` and `D2` has same dimension and `std::declval<T1>() - std::declval<T2>()` is valid expression |
| `q1 * q2`  |                   `std::declval<T1>() * std::declval<T2>()` is valid expression                    |
| `q1 / q2`  |                   `std::declval<T1>() / std::declval<T2>()` is valid expression                    |
|  `q1 * v`  |                   `std::declval<T1>() * std::declval<T3>()` is valid expression                    |
|  `v * q1`  |                   `std::declval<T3>() * std::declval<T1>()` is valid expression                    |
|  `q1 / v`  |                   `std::declval<T1>() / std::declval<T3>()` is valid expression                    |

Otherwise, arithmetic operators do not participate in overload resolution.

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/si_units/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    quantity_t a = 4 | si::meters;
    quantity_t b = 2 | si::meters;

    a + b; // 6 [m]
    a - b; // 2 [m]
    a * b; // 8 [m^2]
    a / b; // 2 [dimensionless]
    2 * b; // 8 [m]
    b * 2; // 8 [m]
    b / 2; // 1 [m]
}
// end example
```

## Unit conversions
----------------------------

If unit conversion occurs, it is always converted to the higher precision.
For example, meters plus millimeters convert meters to millimeters.

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/si_units/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    quantity_t a = 4 | si::meters;
    quantity_t b = 2 | si::millimeters;

    a + b; // 4002 [mm]
    a - b; // 3998 [mm]
    a * b; // 8000 [mm^2]
    a / b; // 2000 [dimensionless]
}
// end example
```

