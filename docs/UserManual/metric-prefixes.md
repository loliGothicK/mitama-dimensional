# Metric prefixes
---------------

# Metric prefix constants for dimensional quantifiers

**definition**

```cpp
namespace mitama::systems::si {
inline constexpr auto pico = std::pico{};
inline constexpr auto nano = std::nano{};
inline constexpr auto micro = std::micro{};
inline constexpr auto milli = std::milli{};
inline constexpr auto centi = std::centi{};
inline constexpr auto deci = std::deci{};
inline constexpr auto deca = std::deca{};
inline constexpr auto hecto = std::hecto{};
inline constexpr auto kilo = std::kilo{};
inline constexpr auto mega = std::mega{};
inline constexpr auto giga = std::giga{};
inline constexpr auto tera = std::tera{};
}
```

**Usage** 

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/prefix.hpp>

int main() {
    using mitama::quantity_t;
    namespace si = mitama::systems::si;

    quantity_t a = (1 | si::giga * si::meters); // 1 [Gm]
}
// end example
```