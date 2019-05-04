#ifndef MITAMA_DIMENSIONAL_DELTA_HPP
#define MITAMA_DIMENSIONAL_DELTA_HPP
#include "quantity.hpp"
#include "nonsi_units/degree_celsius.hpp"
#include "si_units/kelvin.hpp"
#include <type_traits>

namespace mitama {

template < class > struct is_temperature_quantity: std::false_type {};
template < class T > struct is_temperature_quantity<quantity_t<si::kelvin_t, T>>: std::true_type {};
template < class T > struct is_temperature_quantity<quantity_t<nonsi::degree_celsius_t, T>>: std::true_type {};

template < class T > inline constexpr bool is_temperature_quantity_v = is_temperature_quantity<T>::value;

template <class,class=void>
class delta;

template < class >
struct is_delta: std::false_type {};

template < class T >
struct is_delta<delta<T, void>>: std::true_type {};

template < class T >
inline constexpr bool is_delta_v = is_delta<T>::value;

template < class T >
class delta<T, std::enable_if_t<is_quantity_v<T>>> {
  T value_;
public:
  using value_type = T;
  delta() = delete;

  template <class U = T,
            std::enable_if_t<
                  std::is_constructible_v<T, U> &&
                  !std::is_convertible_v<U, T>
            , bool> = false>
  constexpr explicit delta(U && u) noexcept(std::is_nothrow_constructible_v<T, U>)
      : value_(std::forward<U>(u)) {}

  template <typename U = T,
            std::enable_if_t<
                  std::is_constructible_v<T, U> &&
                  std::is_convertible_v<U, T>
            , bool> = false>
  constexpr delta(U && u) noexcept(std::is_nothrow_constructible_v<T, U>)
      : value_(std::forward<U>(u)) {}

  T value() const { return value_; }

  friend std::ostream& operator<<(std::ostream& os, delta const& d) {
    return os << d.value_;
  }
};

template <class T> delta(T&&) -> delta<std::decay_t<T>>;

// specialization for temperature
template < class T, class Quantity,
          std::enable_if_t<is_temperature_quantity_v<T> && is_temperature_quantity_v<std::decay_t<Quantity>>, bool> = false>
Quantity operator+(delta<T> const& d, Quantity const& q){
  return q + Quantity(d.value().value());
}
template < class T, class Quantity,
          std::enable_if_t<is_temperature_quantity_v<T> && is_temperature_quantity_v<std::decay_t<Quantity>>, bool> = false>
Quantity operator+(Quantity const& q, delta<T> const& d){
  return q + Quantity(d.value().value());
}

template < class T, class Quantity,
          std::enable_if_t<is_temperature_quantity_v<T> && is_temperature_quantity_v<std::decay_t<Quantity>>, bool> = false>
Quantity operator-(delta<T> const& d, Quantity const& q){
  return Quantity(d.value().value()) - q;
}
template < class T, class Quantity,
          std::enable_if_t<is_temperature_quantity_v<T> && is_temperature_quantity_v<std::decay_t<Quantity>>, bool> = false>
Quantity operator-(Quantity const& q, delta<T> const& d){
  return q - Quantity(d.value().value());
}

template < class T, class Quantity,
          std::enable_if_t<!is_temperature_quantity_v<T> || !is_temperature_quantity_v<std::decay_t<Quantity>>, bool> = false,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() + std::declval<Quantity>())>>, bool> = false>
Quantity operator+(delta<T> const& d, Quantity const& q){
  return q + Quantity(d.value());
}
template < class T, class Quantity,
          std::enable_if_t<!is_temperature_quantity_v<T> || !is_temperature_quantity_v<std::decay_t<Quantity>>, bool> = false,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() + std::declval<Quantity>())>>, bool> = false>
Quantity operator+(Quantity const& q, delta<T> const& d){
  return q + Quantity(d.value());
}
template < class T, class U,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() + std::declval<U>())>>, bool> = false>
auto operator+(delta<T> const& d1, delta<U> const d2){
  return d1.value() + d2.value();
}
template < class T, class Quantity,
          std::enable_if_t<!is_temperature_quantity_v<T> || !is_temperature_quantity_v<std::decay_t<Quantity>>, bool> = false,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() - std::declval<Quantity>())>>, bool> = false>
Quantity operator-(delta<T> d, Quantity const& q){
  return Quantity(d.value()) - q;
}
template < class T, class Quantity,
          std::enable_if_t<!is_temperature_quantity_v<T> || !is_temperature_quantity_v<std::decay_t<Quantity>>, bool> = false,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() - std::declval<Quantity>())>>, bool> = false>
Quantity operator-(Quantity const& q, delta<T> d){
  return q - Quantity(d.value());
}
template < class T, class U,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() - std::declval<U>())>>, bool> = false>
auto operator-(delta<T> d1, delta<U> d2){
  return d1.value() - d2.value();
}
template < class T, class Quantity,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() * std::declval<Quantity>())>>, bool> = false>
auto operator*(delta<T> d, Quantity const& q){
  return q * d.value();
}
template < class T, class Quantity,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() * std::declval<Quantity>())>>, bool> = false>
auto operator*(Quantity const& q, delta<T> d){
  return q * d.value();
}
template < class T, class U,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() * std::declval<U>())>>, bool> = false>
auto operator*(delta<T> d1, delta<U> d2){
  return d1.value() * d2.value();
}
template < class T, class Quantity,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() / std::declval<Quantity>())>>, bool> = false>
auto operator/(delta<T> d, Quantity const& q){
  return d.value() / q;
}
template < class T, class Quantity,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() / std::declval<Quantity>())>>, bool> = false>
auto operator/(Quantity const& q, delta<T> d){
  return q / d.value();
}
template < class T, class U,
          std::enable_if_t<is_quantity_v<std::decay_t<decltype(std::declval<T>() / std::declval<U>())>>, bool> = false>
auto operator/(delta<T> d1, delta<U> d2){
  return d1.value() / d2.value();
}
}

#endif