#pragma once
#include "dimensional_phantom.hpp"
#include <ratio>

namespace mitama {
// Dimension Types

template <class Dim, class Exponent = std::ratio<1>,
          class Scale = std::ratio<1>>
struct units_t : private dimension_tag<Dim, Exponent> {
  static_assert(std::ratio_greater_v<Scale, std::ratio<0>>,
                "scale must be positive number!");
  using dimension_type = Dim;
  using exponent = Exponent;
  using scale = Scale;
  using tag = dimension_tag<Dim, Exponent>;
  using basic_type = units_t<Dim, std::ratio<1>, Scale>;
};

template <class> struct is_units : std::false_type {};

template <class D, class E, class S>
struct is_units<units_t<D, E, S>> : std::true_type {};

template <class U> inline constexpr bool is_units_v = is_units<U>::value;

template <class D> using make_unit_t = make_dimensional_t<units_t<D>>;

template <class, class> struct scaled_unit;

template <class Base, class Scale>
struct scaled_unit<dimensional_t<Base>, Scale> {
  using type = make_dimensional_t<
      units_t<typename Base::dimension_type, typename Base::exponent, Scale>>;
};

template <class Base, class R>
using scaled_unit_t = typename scaled_unit<Base, R>::type;
} // namespace mitama