# class quantity

## Constructors and Destructors

### default constructor

```cpp
  constexpr quantity_t(): value_{} {}
```

### Constructors for value

Initializes the contained value as if in-place-initializing with expression `T(std::forward<Args>(args)...)`.

```cpp
template <class U, 
std::enable_if_t<std::is_constructible_v<T, U> &&
                                        std::is_convertible_v<U, T>,
                                    bool> = false>
constexpr quantity_t(U &&u) : value_(std::forward<U>(u)) {}

template <class U, std::enable_if_t<std::is_constructible_v<T, U> &&
                                        !std::is_convertible_v<U, T>,
                                    bool> = false>
explicit constexpr quantity_t(U &&u) : value_{std::forward<U>(u)} {}
```

### Copy constructors for linear scale quantities

Initializes the contained value from `o.value`, and conversion factor is calculated automatically.

```cpp
template <
    class D, class U,
    std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U>> &&
                        std::is_constructible_v<T, U> &&
                        std::is_convertible_v<U, T>,
                    bool> = false>
constexpr quantity_t(quantity_t<D, U> const &o)
    : value_(mitamagic::converted_value<quantity_t>(o)) {}

template <
    class D, class U,
    std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U>> &&
                        std::is_constructible_v<T, U> &&
                        !std::is_convertible_v<U, T>,
                    bool> = false>
explicit constexpr quantity_t(quantity_t<D, U> const &o)
    : value_{mitamagic::converted_value<quantity_t>(o)} {}
```

### Copy constructors for non-linear scale quantities

Initializes contained value using `converter`.
This constructor may shall call between absolute temperature and celsius temperature or between radian and celsius angle.

```cpp
template <
    class D, class U,
    std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U>, quantity_t>> &&
                        std::is_constructible_v<T, U> &&
                        std::is_convertible_v<U, T>,
                    bool> = false>
constexpr quantity_t(quantity_t<D, U> const &o)
    : value_(::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o)) {}

template <
    class D, class U,
    std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U>, quantity_t>> &&
                        std::is_constructible_v<T, U> &&
                        !std::is_convertible_v<U, T>,
                    bool> = false>
explicit constexpr quantity_t(quantity_t<D, U> const &o)
    : value_{::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o)} {}
```

### Copy assignment operator

Copy initializes the contained value from `o.value` and conversion factor is calculated automatically.


```cpp
template <
    class D, class U,
    std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U>> &&
                        std::is_convertible_v<U, T>,
                    bool> = false>
constexpr quantity_t &operator=(quantity_t<D, U> const &o) & {
    this->value_ = mitamagic::converted_value<quantity_t>(o);
    return *this;
}

template <
    class D, class U,
    std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U>, quantity_t>> &&
                        std::is_convertible_v<U, T>,
                    bool> = false>
constexpr quantity_t &operator=(quantity_t<D, U> const &o) & {
    this->value_ = ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
    return *this;
}
```

## Comparisons

!!! Note
    This operator shall not participate in overload resolution unless `is_{xxx}_comparable<T, U>` is true. `{xxx}` denotes equal (`==`), not_equal (`!=`), less (`<`), less_or_equal (`<=`), greater (`>`) or greater_or_equal (`>=`).

### operator ==

```cpp
template <
    class D, class U,
    std::enable_if_t<
    std::conjunction_v<
        is_complete_type<::mitama::converter<quantity_t<D, U>, quantity_t>>,
        is_equal_comparable<T, U>>
    , bool> = false>
constexpr bool operator==(quantity_t<D, U> const &o) const {
    return this->value_ == ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
}

template <
    class D, class U,
    std::enable_if_t<
    std::conjunction_v<
        is_same_dimensional<quantity_t, quantity_t<D, U>>,
        is_equal_comparable<T, U>>
    , bool> = false>
constexpr bool operator==(quantity_t<D, U> const &o) const {
    return this->value_ == mitamagic::converted_value<quantity_t>(o);
}
```

### operator !=

```cpp
template <
    class D, class U,
    std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U>, quantity_t>>,
                    bool> = false>
constexpr bool operator!=(quantity_t<D, U> const &o) const {
    return this->value_ != ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
}

template <
    class D, class U,
    std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U>>,
                    bool> = false>
constexpr bool operator!=(quantity_t<D, U> const &o) const {
    return this->value_ != mitamagic::converted_value<quantity_t>(o);
}
```

### operator <

```cpp
template <
    class D, class U,
    std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U>, quantity_t>>,
                    bool> = false>
constexpr bool operator<(quantity_t<D, U> const &o) const {
    return this->value_ < ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
}

template <
    class D, class U,
    std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U>>,
                    bool> = false>
constexpr bool operator<(quantity_t<D, U> const &o) const {
    return this->value_ < mitamagic::converted_value<quantity_t>(o);
}
```

### operator <=

```cpp
template <
    class D, class U,
    std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U>, quantity_t>>,
                    bool> = false>
constexpr bool operator<=(quantity_t<D, U> const &o) const {
    return this->value_ <= ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
}

template <
    class D, class U,
    std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U>>,
                    bool> = false>
constexpr bool operator<=(quantity_t<D, U> const &o) const {
    return this->value_ <= mitamagic::converted_value<quantity_t>(o);
}
```

### operator >

```cpp
template <
    class D, class U,
    std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U>, quantity_t>>,
                    bool> = false>
constexpr bool operator>(quantity_t<D, U> const &o) const {
    return this->value_ > ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
}

template <
    class D, class U,
    std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U>>,
                    bool> = false>
constexpr bool operator>(quantity_t<D, U> const &o) const {
    return this->value_ > mitamagic::converted_value<quantity_t>(o);
}
```

### operator >=

```cpp
template <
    class D, class U,
    std::enable_if_t<is_complete_type_v<::mitama::converter<quantity_t<D, U>, quantity_t>>,
                    bool> = false>
constexpr bool operator>=(quantity_t<D, U> const &o) const {
    return this->value_ >= ::mitama::converter<quantity_t<D, U>, quantity_t>::convert(o);
}

template <
    class D, class U,
    std::enable_if_t<is_same_dimensional_v<quantity_t, quantity_t<D, U>>,
                    bool> = false>
constexpr bool operator>=(quantity_t<D, U> const &o) const {
    return this->value_ >= mitamagic::converted_value<quantity_t>(o);
}
```

## Accessor

### value()

Returns contained value.

```cpp
constexpr T value() const { return value_; }
```

## operator | for dimensional quantifier

It is allowed to convert values into quantities by piping a value to dimensional quantifiers.

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>

int main() {
    namespace si = mitama::si;
    using mitama::quantity_t;

    // using template argument deduction for class templates

    quantity_t mass = 3 | si::kilograms; // 3 [kg]

    quantity_t time = 1.66 | si::seconds; // 1.66 [s]

    quantity_t volume = 4 | si::meter<3>; // 4 [m^3]
    //                               ^~~ variable template
}
// end example
```