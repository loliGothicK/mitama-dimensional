# Math functions for quantity

## abs.hpp

### abs( quantity )

Calculates absolute value of quantity.

```cpp
template < template <class> class Synonym, class T, class... Units >
auto abs(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return std::decay_t<decltype(quantity)>{ std::abs(quantity.value()) };
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
    return {std::log2(q.value())};
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
    return {std::log10(q.value())};
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
    return {std::log1p(q.value())};
}
```

## minmax.hpp

### min( quantities... )

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



```cpp
template < class Q1, class Q2 >
auto dim(Q1&& q1, Q2&& q2) -> ::mitama::common_type_t<Q1, Q2>
{
  return ::mitama::common_type_t<Q1, Q2>( std::fdim(std::forward<Q1>(q1).value(), std::forward<Q2>(q2).value()) );
}
```