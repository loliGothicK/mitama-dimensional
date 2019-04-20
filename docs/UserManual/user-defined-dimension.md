# How to define dimension class
-------------------------------

>"Fear of a C++ only increases fear of the thing itself."

## dimension type

All that is required to behave as a dimension type is to define a void type alias named `is_base_dimension` as a type member.

```cpp
struct wizarding_currency {
    using is_base_dimension = void;
};
```

## Base unit type

Use `mitama::make_unit_t` to get base unit types from dimension types.

```cpp
using knut_t = mitama::make_unit_t<wizarding_currency>;
```

## Scaled unit type

Use `mtiama::make_unit_t` to get scaled unit types from base unit types. 

```cpp
using sickle_t = mitama::scaled_unit_t<knut_t, std::ratio<29>>;
using galleon_t = mitama::scaled_unit_t<sickle_t, std::ratio<17>>;
```

## Dimensional quantifiers [option]


```cpp
inline constexpr knut_t knuts{};
inline constexpr knut_t knut{};

inline constexpr sickle_t sickles{};
inline constexpr sickle_t sickle{};

inline constexpr galleon_t galleons{};
inline constexpr galleon_t galleon{};
```

## Format [option]

Define specializations to enable formatted output.

```cpp
namespace mitama {
    template <> struct abbreviation<wizarding::knut_t>
        { static constexpr char str[] = "knuts"; };
    template <> struct abbreviation<wizarding::sickle_t>
        { static constexpr char str[] = "sickles"; };
    template <> struct abbreviation<wizarding::galleon_t>
        { static constexpr char str[] = "galleons"; };
}
```
