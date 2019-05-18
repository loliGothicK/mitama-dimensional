# Meta functions

## struct is_quantity&lt;T&gt;

Checks whether T is a quantity_t.
Provides the member constant value that is equal to true,
if T is the type quantity_t,
const quantity_t, volatile quantity_t,
or const volatile quantity_t.
Otherwise, value is equal to false.

**definition**

```cpp
template <class T> struct is_quantity : std::false_type {};

template <class D, class T>
struct is_quantity<quantity_t<D, T>> : std::true_type {};

template <class T> inline constexpr bool is_quantity_v = is_quantity<T>::value;
```

## struct is_units&lt;T&gt;

Checks whether `T` is a `units_t`.
Provides the member constant value that is equal to true,
if `T` is the type `units_t`,
`const units_t`, `volatile units_t`,
or `const volatile units_t`.
Otherwise, value is equal to false.

**definition**

```cpp
template <class> struct is_units : std::false_type {};

template <class D, class E, class S>
struct is_units<units_t<D, E, S>> : std::true_type {};

template <class U> inline constexpr bool is_units_v = is_units<U>::value;
```

## struct is_dimensional&lt;T&gt;

Checks whether `T` is a `dimensional_t`.
Provides the member constant value that is equal to true,
if `T` is the type `dimensional_t`,
`const dimensional_t`, `volatile dimensional_t`,
or `const volatile dimensional_t`.
Otherwise, value is equal to false.

**definition**

```cpp
template <class> struct is_dimensional : std::false_type {};

template <template <class> class Synonym, class... Units>
struct is_dimensional<Synonym<dimensional_t<Units...>>> : std::true_type {};

template <class D>
inline constexpr bool is_dimensional_v = is_dimensional<D>::value;
```

## struct is_same_dimensional&lt;quantity_t<D1, T>, quantity_t<D2, U>&gt;

Checks whether `quantity_t<D1, T>` and `quantity_t<D2, U>` have same dimension.
Provides the member constant value that is equal to true,
if `quantity_t<D1, T>` and `quantity_t<D2, U>` have same dimension,
Otherwise, value is equal to false.

**definition**

```cpp
template <class, class> struct is_same_dimensional : std::false_type {};

template <class T, class U,
            class... Units1,
            class... Units2,
            template <class> class Synonym1,
            template <class> class Synonym2>
struct is_same_dimensional<quantity_t<Synonym1<dimensional_t<Units1...>>, T>,
                           quantity_t<Synonym2<dimensional_t<Units2...>>, U>>
    : std::conjunction<
        std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
        std::is_base_of<typename Units1::tag,
                        dimensional_t<Units2...>>...> {};

template <class... Units1,
          class... Units2,
          template <class> class Synonym1,
          template <class> class Synonym2>
struct is_same_dimensional<Synonym1<dimensional_t<Units1...>>,
                           Synonym2<dimensional_t<Units2...>>>
    : std::conjunction<
        std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
        std::is_base_of<typename Units1::tag,
                        dimensional_t<Units2...>>...> {};

template <class... Units1,
          class... Units2>
struct is_same_dimensional<dimensional_t<Units1...>,
                           dimensional_t<Units2...>>
    : std::conjunction<
        std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>,
        std::is_base_of<typename Units1::tag,
                        dimensional_t<Units2...>>...> {};

template <class L, class R>
inline constexpr bool is_same_dimensional_v = is_same_dimensional<L, R>::value;
```


## struct remove_dim_if&lt;template &lt;class&gt; class Pred, quantity_t<D..., T>&gt;

Makes a `quantity_t<E ...>` consisting of the dimensions of `E ...` except where `Pred<D_i>::value` is false.
Provides the member type that is `quantity_t<E ...>`.

## struct is_dimensional_quantifier&lt;T&gt;

Checks whether T is a `TT<dimensional_t<D...>>` (TT is a variadic template template).
Provides the member constant value that is equal to true,
if T is the type `TT<dimensional_t<D...>>`,
`const TT<dimensional_t<D...>>`, `volatile TT<dimensional_t<D...>>`,
or `const volatile TT<dimensional_t<D...>>`.
Otherwise, value is equal to false.

