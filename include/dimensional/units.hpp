#ifndef MITAMA_DIMENSIONAL_UNITS_HPP
#define MITAMA_DIMENSIONAL_UNITS_HPP
#include <dimensional/fwd/units_fwd.hpp>
#include <dimensional/dimensional.hpp>
#include <dimensional/dimensional_traits.hpp>
#include <ratio>

namespace mitama {

template < int N, class BaseDim, class Characteristic, class Scale, class... BaseUnits >
struct unit_type_with_system {
  using type = make_dimensional_t<units_t<N, BaseDim, Characteristic, Scale, system<BaseUnits...>>>;
};

template < int N, class BaseDim, class Characteristic, class Scale, class... BaseUnits >
struct unit_type_with_system<N, BaseDim, Characteristic, Scale, system<BaseUnits...>> {
  using type = make_dimensional_t<units_t<N, BaseDim, Characteristic, Scale, system<BaseUnits...>>>;
};

template <int N, class BaseDim, class Characteristic, class Scale, class System>
struct units_t : private dimension_tag<N, BaseDim, Characteristic> {
  static_assert(std::ratio_greater_v<Scale, std::ratio<0>>,
                "scale must be positive number!");
  static constexpr int index = N;
  using dimension_type = BaseDim;
  using exponent = Characteristic;
  using scale = Scale;
  using tag = dimension_tag<N, BaseDim, Characteristic>;
  using unit_type = make_dimensional_t<units_t<N, BaseDim, Characteristic, Scale>>;
  template < class... Base >
  using unit_type_with_system = typename unit_type_with_system<N, BaseDim, Characteristic, Scale, Base...>::type;
  using system_type = System;
};

template < class BaseDim, int N >
struct base_units : units_t<N, BaseDim> {};

template <class, class> struct scaled_unit;

template <template <class> class Synonym, class Base, class Scale>
struct scaled_unit<Synonym<dimensional_t<Base>>, Scale> {
  using type = make_dimensional_t<
      units_t<Base::index, typename Base::dimension_type, typename Base::exponent, std::ratio_multiply<typename Base::scale, Scale>>>;
};

template <class Base, class R>
using scaled_unit_t = typename scaled_unit<Base, R>::type;
} // namespace mitama

#endif