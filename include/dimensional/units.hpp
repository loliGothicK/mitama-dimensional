#ifndef MITAMA_DIMENSIONAL_UNITS_HPP
#define MITAMA_DIMENSIONAL_UNITS_HPP
#include "fwd/units_fwd.hpp"
#include "dimensional_phantom.hpp"
#include "dimensional_traits.hpp"
#include <ratio>

namespace mitama {
// Dimension Types

template <class Dim, class Exponent, class Scale>
struct units_t : private dimension_tag<Dim, Exponent> {
  static_assert(std::ratio_greater_v<Scale, std::ratio<0>>,
                "scale must be positive number!");
  using dimension_type = Dim;
  using exponent = Exponent;
  using scale = Scale;
  using tag = dimension_tag<Dim, Exponent>;
  using basic_type = units_t<Dim, std::ratio<1>, Scale>;
};

template <class D> using make_unit_t = make_dimensional_t<units_t<D>>;

template <class, class> struct scaled_unit;

template <template <class> class Synonym, class Base, class Scale>
struct scaled_unit<Synonym<dimensional_t<Base>>, Scale> {
  using type = make_dimensional_t<
      units_t<typename Base::dimension_type, typename Base::exponent, std::ratio_multiply<typename Base::scale, Scale>>>;
};

template <class Base, class R>
using scaled_unit_t = typename scaled_unit<Base, R>::type;
} // namespace mitama

#endif