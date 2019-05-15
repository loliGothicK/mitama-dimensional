# Math functions for quantity

## abs.hpp

### abs( quantity )

Calculates absolute value of quantity.

```cpp
template < template <class> class Synonym, class T, class... Units >
auto abs(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    using std::abs;
    return std::decay_t<decltype(quantity)>{ abs(quantity.value()) };
}
```

## logarithm.hpp

### log( quantity )

Calculates $log$ of quantity and returns dimensionless quantity.

```cpp
template <template <class> class Repr,
          class T, class... Units >
auto log(quantity_t<Repr<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units_repr<dimensional_t<>>, T>
{
    using std::log;
    return {std::log(q.value())};
}
```

### log2( quantity )

Calculates $log2$ of quantity and returns dimensionless quantity.

```cpp
template <template <class> class Repr,
          class T, class... Units >
auto log2(quantity_t<Repr<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units_repr<dimensional_t<>>, T>
{
    using std::log2;
    return {log2(q.value())};
}
```

### log10( quantity )

Calculates $log10$ of quantity and returns dimensionless quantity.

```cpp
template <template <class> class Repr,
          class T, class... Units >
auto log10(quantity_t<Repr<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units_repr<dimensional_t<>>, T>
{
    using std::log10;
    return {log10(q.value())};
}
```

### log1p( quantity )

Calculates $log1p$ of quantity and returns dimensionless quantity.

```cpp
template <template <class> class Repr,
          class T, class... Units >
auto log1p(quantity_t<Repr<dimensional_t<Units...>>, T> const& q)
    -> quantity_t<si_base_units_repr<dimensional_t<>>, T>
{
    using std::log1p;
    return {log1p(q.value())};
}
```

## minmax.hpp

### min( quantities... )

Calculates $min$ of quantities.
Units conversion is perform automatically.

```cpp
template <class First, class Second, class... Quantities
        , std::enable_if_t<std::conjunction_v<is_quantity<std::decay_t<First>>, is_quantity<std::decay_t<Second>>, is_quantity<std::decay_t<Quantities>>...>, bool> = false>
auto min(First first, Second second, Quantities... quantities)
  -> ::mitama::common_type_t<First, Second, Quantities...>
{
  using ret = ::mitama::common_type_t<First, Second, Quantities...>;
  if constexpr (sizeof...(Quantities) == 0) {
    return first < second ? static_cast<ret>(first) : static_cast<ret>(second);
  } else {
    return ::mitama::min(first < second ? static_cast<ret>(first)
                                        : static_cast<ret>(second),
                         quantities...);
  }
}
```

### max( quantities... )

Calculates $max$ of quantities.
Units conversion is perform automatically.

```cpp
template <class First, class Second, class... Quantities
        , std::enable_if_t<std::conjunction_v<is_quantity<std::decay_t<First>>, is_quantity<std::decay_t<Second>>, is_quantity<std::decay_t<Quantities>>...>, bool> = false>
auto max(First first, Second second, Quantities... quantities)
  -> ::mitama::common_type_t<First, Second, Quantities...>
{
  using ret = ::mitama::common_type_t<First, Second, Quantities...>;
  if constexpr (sizeof...(Quantities) == 0) {
    return first > second ? static_cast<ret>(first) : static_cast<ret>(second);
  } else {
    return ::mitama::max(first > second ? static_cast<ret>(first)
                                        : static_cast<ret>(second),
                         quantities...);
  }
}
```

### fdim( quantity, quantity )

Calculates $fdim$ of quantities.
Units conversion is perform automatically.

```cpp
template < class Q1, class Q2 >
auto fdim(Q1&& q1, Q2&& q2) -> ::mitama::common_type_t<Q1, Q2>
{
  using std::fdim;
  return ::mitama::common_type_t<Q1, Q2>( fdim(std::forward<Q1>(q1).value(), std::forward<Q2>(q2).value()) );
}
```

## modular.hpp

### fmod( quantity, quantity )

Calculates $fdim$ of quantities.

```cpp
template <template <class> class Synonym1,
          template <class> class Synonym2,
          class T1, class... Units1,
          class T2, class... Units2 >
auto fmod(quantity_t<Synonym1<dimensional_t<Units1...>>, T1> const& q1,
          quantity_t<Synonym2<dimensional_t<Units2...>>, T2> const& q2)
    -> std::enable_if_t<std::is_convertible_v<T1, long double> && std::is_convertible_v<T2, long double>,
            std::decay_t<decltype(q1/q2)>>
{
    using std::fmod;
    return std::decay_t<decltype(q1/q2)>(fmod(q1.value(), q2.value()));
}
```

### fmod( quantity, value )

Calculates $fmod$ of quantity and value.

```cpp
template < template <class> class Synonym, class T, class... Units >
auto fmod(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity,
          typename quantity_t<Synonym<dimensional_t<Units...>>, T>::value_type value)
{
    using std::fmod;
    return std::decay_t<decltype(quantity)>{ fmod(quantity.value(), value) };
}
```

### remainder( quantity, quantity )

Calculates $remainder$ of quantities.

```cpp
template <template <class> class Synonym1,
          template <class> class Synonym2,
          class T1, class... Units1,
          class T2, class... Units2 >
auto remainder(quantity_t<Synonym1<dimensional_t<Units1...>>, T1> const& q1,
               quantity_t<Synonym2<dimensional_t<Units2...>>, T2> const& q2)
    -> std::enable_if_t<std::is_convertible_v<T1, long double> && std::is_convertible_v<T2, long double>,
            std::decay_t<decltype(q1/q2)>>
{
    using std::remainder;
    return std::decay_t<decltype(q1/q2)>(remainder(q1.value(), q2.value()));
}
```

### remainder( quantity, value )

Calculates $remainder$ of quantity and value.

```cpp
template < template <class> class Synonym, class T, class... Units >
auto remainder(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity,
               typename quantity_t<Synonym<dimensional_t<Units...>>, T>::value_type value)
{
    using std::remainder;
    return std::decay_t<decltype(quantity)>(remainder(quantity.value(), value));
}
```

## nearest_integer.hpp

### ceil( quantity )

Calculates $ceil$ of quantity and value.

```cpp
template <template<class> class Synonym, class T, class... Units>
auto ceil(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::ceil;
  return std::decay_t<decltype(quantity)>{ceil(quantity.value())};
}
```

### floor( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto floor(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::floor;
  return std::decay_t<decltype(quantity)>{floor(quantity.value())};
}
```

### trunc( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto trunc(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::trunc;
  return std::decay_t<decltype(quantity)>{trunc(quantity.value())};
}
```

### round( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto round(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::round;
  return std::decay_t<decltype(quantity)>{round(quantity.value())};
}
```

### lround( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto lround(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::lround;
  return quantity_t<Synonym<dimensional_t<Units...>>, long>{
      lround(quantity.value())};
}
```

### llround( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto llround(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::llround;
  return quantity_t<Synonym<dimensional_t<Units...>>, long long>{
      llround(quantity.value())};
}
```

### nearbyint( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto nearbyint(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::nearbyint;
  return std::decay_t<decltype(quantity)>{nearbyint(quantity.value())};
}
```

### rint( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto rint(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::rint;
  return std::decay_t<decltype(quantity)>{rint(quantity.value())};
}
```

### lrint( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto lrint(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using lrint;
  return quantity_t<Synonym<dimensional_t<Units...>>, long>{
      lrint(quantity.value())};
}
```

### llrint( quantity )

```cpp
template <template<class> class Synonym, class T, class... Units>
auto llrint(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  using std::llrint;
  return quantity_t<Synonym<dimensional_t<Units...>>, long long>{
      llrint(quantity.value())};
}
```

## pow.hpp

### pow&lt;N&gt;( quantity )

```cpp
template < class Exp, template <class> class Synonym, class T, class... Units >
auto pow(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    using std::pow;
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, Exp>::type>, T>
        {
            static_cast<T>(pow(quantity.value(), static_cast<long double>(Exp::num) / Exp::den))
        };
}
```

### pow&lt;std::ratio<N,D>&gt;( quantity )

```cpp
template < std::intmax_t Exp, template <class> class Synonym, class T, class... Units >
auto pow(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    using std::pow;
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<Exp>>::type>, T>
        {
            static_cast<T>(pow(quantity.value(), static_cast<long double>(Exp)))
        };
}
```

### square( quantity )

```cpp
template < template <class> class Synonym, class T, class... Units >
auto square(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<2>>::type>, T>
        {
            static_cast<T>(quantity.value() * quantity.value())
        };
}
```

### cubic( quantity )

```cpp
template < template <class> class Synonym, class T, class... Units >
auto cubic(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<3>>::type>, T>
        {
            static_cast<T>(quantity.value() * quantity.value() * quantity.value())
        };
}
```

## sqrt.hpp

### sqrt( quantity )

```cpp
template < template <class> class Synonym, class T, class... Units >
auto sqrt(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<1, 2>>::type>, T>
        {
            static_cast<T>(std::sqrt(quantity.value()))
        };
}
```

### cbrt( quantity )

```cpp
template < template <class> class Synonym, class T, class... Units >
auto cbrt(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<1, 3>>::type>, T>
        {
            static_cast<T>(std::cbrt(quantity.value()))
        };
}
```

### hypot( radian, radian, [radian] ) -> value

```cpp
template < class... Quantities,
    std::enable_if_t<(sizeof...(Quantities) == 2 || sizeof...(Quantities) == 3)
                  && std::conjunction_v<::mitama::is_same_dimensional<Quantities, ::mitama::quantity<systems::si::meter_t>>...>,
                bool> = false>
auto hypot(Quantities... quantities) {
    return ::mitama::common_type_t<std::decay_t<Quantities>...>{ std::hypot(static_cast<::mitama::common_type_t<std::decay_t<Quantities>...>>(quantities).value()...) };
}
```

## trigonometric

### sin( radian ) -> value

```cpp
template < class T >
auto sin(quantity<systems::si::radian_t, T> const& rad) {
    return std::sin(rad.value());
}
```

### cos( radian ) -> value

```cpp
template < class T >
auto cos(quantity<systems::si::radian_t, T> const& rad) {
    return std::cos(rad.value());
}
```

### tan( radian ) -> value

```cpp
template < class T >
auto tan(quantity<systems::si::radian_t, T> const& rad) {
    return std::tan(rad.value());
}
```

### asin( value ) -> radian

```cpp
template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
auto asin(T const& v) {
    return std::asin(v) | systems::si::radian;
}
```

### acos( value ) -> radian

```cpp
template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
auto acos(T const& v) {
    return std::acos(v) | systems::si::radian;
}
```

### atan( value ) -> radian

```cpp
template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
auto atan(T const& v) {
    return std::atan(v) | systems::si::radian;
}
```