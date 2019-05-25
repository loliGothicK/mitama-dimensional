![logo](https://github.com/LoliGothick/mitama-dimensional/blob/master/mitama-dimensional-logo.png)

[![CircleCI](https://circleci.com/gh/LoliGothick/mitama-dimensional.svg?style=svg)](https://circleci.com/gh/LoliGothick/mitama-dimensional)

[![Build status](https://ci.appveyor.com/api/projects/status/3wv0d11ovfagkmvy/branch/master?svg=true)](https://ci.appveyor.com/project/LoliGothick/mitama-dimensional/branch/master)

## What is mitama-dimensional?

Header-only C++17 library provides dimensional analysis based on variadic Phantom-Type.
Please refer to the [document](https://loligothick.github.io/mitama-dimensional/) for more details.

## Features

- quantity_t, which is a dimensionful value wrapper
- arithmetic operators for quantity
- automated unit conversions
- math functions for quantity
- pre defined SI derived units
- **USER DEFINED DIMENSION**
- formatted output
- dimensional refinement

## Examples

- [quantity and arithmetic operation](https://loligothick.github.io/mitama-dimensional/UserManual/mitama_quantity_t/)

```cpp
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/area.hpp>

int main() {
    namespace si = mitama::systems::si;
    // width = 2 m
    mitama::quantity_t<si::meter_t, int> width = 2;
    // height = 3 m
    mitama::quantity_t<si::meter_t, int> height = 3;
    // area = 6 m^2
    mitama::quantity_t<si::area_t, int> area = width * height;
}
```

Here is a dimensional sanity check example:

```cpp
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/area.hpp>

int main() {
    namespace si = mitama::systems::si;
    // width = 2 m
    mitama::quantity_t<si::meter_t, int> width = 2;
    // height = 3 m
    mitama::quantity_t<si::meter_t, int> height = 3;
    // ERROR!
    mitama::quantity_t<si::area_t, int> area = width + height;
    //                                               ^ oops!!
}
```

- [dimensional quantifiers](https://loligothick.github.io/mitama-dimensional/UserManual/dimensional-quantifiers/)

```cpp
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/area.hpp>

int main() {
    namespace si = mitama::systems::si;
    // width = 2 m
    mitama::quantity_t width = 2 | si::meters;
    // height = 3 m
    mitama::quantity_t height = 3 | si::meters;
    // area = 6 m^2
    mitama::quantity_t<si::area_t, int> area = width * height;
}
```

- [unit conversions](https://loligothick.github.io/mitama-dimensional/UserManual/mitama_quantity_t/#unit-conversions)
  
```cpp
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/area.hpp>

int main() {
    namespace si = mitama::systems::si;
    // width = 2 m
    mitama::quantity_t<si::meter_t, int> width = 2;
    // height = 3 mm
    mitama::quantity_t<si::millimeter_t, int> height = 3;
    // area = 6000 mm^2
    mitama::quantity_t area = width * height;
}
```

- [dimensional refinement](https://loligothick.github.io/mitama-dimensional/UserManual/dimensional-refinement/)
  
```cpp
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/area.hpp>
#include <dimensional/refinement.hpp>

int main() {
    namespace si = mitama::systems::si;
    using mitama::accepts_for, mitama::sym::L;

    // width = 2 m
    mitama::quantity_t<si::meter_t, int> width = 2;
    // height = 3 mm
    mitama::quantity_t<si::millimeter_t, int> height = 3;
    // area = 6000 mm^2
    mitama::quantity_t area = accepts_for<L<2>> |= width * height;
    //                        ^~~~~~~~~~~~~~~~
    //                        refine for L^2
}
```


- [user defined dimension example](https://loligothick.github.io/mitama-dimensional/UserManual/user-defined-dimension/)


```cpp
// wizarding.hpp
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
/*
Here's an example how to implement user extension dimensions
by taking the currency of the wizarding world of Harry Potter.
*/
namespace wizarding {
    // (1) - define base dimension type.
    struct wizarding_currency {
        // required: meta tag type `is_base_dimension`
        using is_base_dimension = void;
    };
    // (2) - define base unit type using `mitama::make_unit_t`.
    using knut_t = mitama::make_unit_t<wizarding_currency>;
    // (3) - define scaled unit aliasing using `mitama::scaled_unit_t<UnitType, Ratio>`.
    // [ - Note:
    //     In Wizarding World of Harry Potter, 1 sickle = 29 knuts and 1 galleon = 17 sickles.
    //   - end note ]
    using sickle_t = mitama::scaled_unit_t<knut_t, std::ratio<29>>;
    using galleon_t = mitama::scaled_unit_t<sickle_t, std::ratio<17>>;

    // (4) - define inline constexpr variables [optional].
    // for operator |
    // [ - Example:
    //     auto x = 42 | knuts; // x: quantity_t<knut_t, int>
    //   - end example ]
    inline constexpr knut_t knuts{};
    inline constexpr knut_t knut{};

    inline constexpr sickle_t sickles{};
    inline constexpr sickle_t sickle{};

    inline constexpr galleon_t galleons{};
    inline constexpr galleon_t galleon{};
}

namespace mitama {
    // (5) - define partial specialization class `abbreviation` for pretty printing [optional].
    template <> struct abbreviation<wizarding::knut_t> { static constexpr char str[] = "knuts"; };
    template <> struct abbreviation<wizarding::sickle_t> { static constexpr char str[] = "sickles"; };
    template <> struct abbreviation<wizarding::galleon_t> { static constexpr char str[] = "galleons"; };
}
```

```cpp
// main.cpp
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
```

## Integration

You should add include directory `include/`.

## Compiler compatibility

* Clang/LLVM >= 6.0
* GCC >= 8
* Visual C++ >= 16.0.0 / Visual Studio >= 2019

## Licensed under the [MIT License](LICENSE)
