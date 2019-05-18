# Metric prefixes
---------------

## Metric prefix for SI

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

## Metric prefix for information

**definition**

```cpp
namespace mitama::systems::information {
inline constexpr auto kibi = std::ratio<(1ll << 10)>{};
inline constexpr auto mebi = std::ratio<(1ll << 20)>{};
inline constexpr auto gibi = std::ratio<(1ll << 30)>{};
inline constexpr auto tebi = std::ratio<(1ll << 40)>{};
inline constexpr auto pebi = std::ratio<(1ll << 50)>{};
inline constexpr auto exbi = std::ratio<(1ll << 60)>{};
}
```

**Usage**

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/systems/information/byte.hpp>
#include <dimensional/systems/information/prefix.hpp>

int main() {
    using mitama::quantity_t;
    namespace info = mitama::systems::information;

    quantity_t a = (1 | info::gibi * info::bytes); // 1 [GiB]
    quantity_t<info::byte_t, int> b = a; // 1'073'741'824 [B]
}
// end example
```
