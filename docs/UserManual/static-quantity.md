# Static quantity

## Motivation

**Q. What are the benefits of treating quantity at compile time?**

**A. Literal refinement at value level is possible at compile time.**

See bellow:

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/static_quantity.hpp>
#include <dimensional/systems/si/meter.hpp>
#include <dimensional/io.hpp>
#include <iostream>

// predicate examples:
template < auto Arg >
struct is_even: std::bool_constant<Arg % 2 == 0> {};

int main(){
    namespace si = mitama::systems::si;
    using mitama::static_quantity, mitama::refined, mitama::quantity_t;
    using namespace mitama::literals::static_quantity_literals;

    constexpr refined<is_even, quantity_t<si::meter_t, int>> r = 2_m;
//            ^~~~~~~ ^~~~~~~  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~      ^~~~
//            |       |        |                                 |
//            |       |        refined type                      static quantity literal                  
//            |       |        
//            |       refinement predicate
//            |
//            refinement type

    // It is a compilation error because a specified predicate `is_even` is not satisfied:

    // constexpr refined<is_even, quantity_t<si::meter_t, int>> error_ = 3_m;

}
// end example
```

## class static_quantity_t

**definition**

```cpp
template < class, auto >
struct static_quantity_t;

template < class... Units, template <class> class Synonym, auto Value >
struct static_quantity_t<Synonym<dimensional_t<Units...>>, Value>
{
    using value_type = decltype(Value);
    using dimension_type = dimensional_t<Units...>;
    static constexpr value_type value = Value;
};
```

`static_quantity_t` is a class for pure compile-time quantity manipulation.
The idea of static quantity is almost same as `std::integral_constant`.

C++17 introduced **declaring non-type template parameters with auto**.
So, `static_quantity_t` is declared as `static_quantity_t<class Dim, auto Value>`.

Use values ​​directly in the template as in `static_quantity_t<meter_t, 2>`.

## static_quantity - a variable template

**definition**

```cpp
template < class Dim, auto Value >
inline constexpr static_quantity_t<Dim, Value> static_quantity{};
```

For long time, C++ meta-programmer using class for compile-time manipulation.

Like below:

```cpp
// for example
// from: https://github.com/nholthaus/units#pure-compile-time-unit-manipulation
struct RightTriangle
{
	using a = unit_value_t<meters, 3>;
	using b = unit_value_t<meters, 4>;
	using c = unit_value_sqrt<
                unit_value_add<
                    unit_value_power<a, 2>,
                    unit_value_power<b, 2>
                >
            >;
};
```

That is elephant.

Using constexpr variable template is elegant solution.

```cpp
// Value level metaprogramming.
// Awesome!!
static_quantity<meter_t, 1> + static_quantity<meter_t, 1>;
// -> static_quantity<meter_t, 2>
```

This technique used in [Boost.Hana ](https://www.boost.org/doc/libs/1_61_0/libs/hana/doc/html/index.html).

Provided operations for `static_quantity`:

- operator +
- operator -
- operator *
- operator /
- pow&lt;N&gt;

## Static quantity literals

Introduce UDLs to make static quantities more convenient.
Since `static_quantity` can only be used as a literal, the description can be shortened by using UDLs.

**definition (for example)**

```cpp
namespace mitama::literals {
inline namespace static_quantity_literals {

inline namespace length_literals {
    template<char... Chars>
    inline constexpr
    static_quantity_t<
        mitama::systems::si::meter_t,
        static_cast<int>(mitamagic::to_decimal_v<Chars...>)> 
    operator"" _m() { return {}; }
}
}}
```

Using UDLs, the above code can be rewritten as follows:

```cpp
using namespace mitama::literals::static_quantity_literals;
1_m + 1_m; // amazing!!!
// -> 2_m (= static_quantity<meter_t, 2>)
```

## Refinement type for static quantities

**definition**

```cpp
template < template <auto> class, class T >
class refined;

template < template < auto > class Pred, class Dim, class T > 
class refined<Pred, quantity_t<Dim, T>> {
    quantity_t<Dim, T> quantity_;
public:
    template < auto Value, class Dimension,
        std::enable_if_t<std::conjunction_v<
            std::is_constructible<
                quantity_t<Dim, T>,
                quantity_t<Dimension, decltype(Value)>>,
            Pred<Value>>
        , bool> = false>
    constexpr refined(static_quantity_t<Dimension, Value>) noexcept
        : quantity_(quantity_t<Dimension, decltype(Value)>(Value))
    {}
};
```

The predicate must be a class template with `auto` as a template parameter.
This is typically write as follows:

```cpp
template < auto A >
struct is_positive: std::bool_constant<(A > -1)> {};
```

### Refined quantity conversion

Refined quantity is convertible to `quantity_t`.

- quantity_t constructor

    `quantity_t<D1, T>` has constructor from `refined<Pred, quantity_t<E, U>>`.
    This constructor shall not participates in overload resolution unless `is_same_dimensional_v<D, E>` is true and `std::is_convertible_v<U, T>` is true.
    Units conversion is automatically performed.

- quantity_t's deduction guide for refined<Pred, quantity_t<D, T>>

    `quantity_t` provides deduction guide for refined:

    ```cpp
    template < template <auto> class Pred, class Dim, class T >
    quantity_t(refined<Pred, quantity_t<Dim, T>>) -> quantity_t<Dim, T>;
    ```

    Therefore, you can infer template parameters as follows:

    ```cpp
    refined<is_positive, quantity_t<si::meter_t, int>> x = 42_m;
    quantity_t y = x; // y: quantity_t<si::meter_t, int>
    ```