#ifndef MITAMA_DIMENSIONAL_MATH_NEARBYINT_HPP
#define MITAMA_DIMENSIONAL_MATH_NEARBYINT_HPP
#include "../quantity.hpp"
#include <cmath>
namespace mitama {
template <template<class> class Repr, class T, class... Units>
auto ceil(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::ceil(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto floor(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::floor(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto trunc(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::trunc(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto round(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::round(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto lround(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return quantity_t<Repr<dimensional_t<Units...>>, long>{
      std::round(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto llround(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return quantity_t<Repr<dimensional_t<Units...>>, long long>{
      std::round(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto nearbyint(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::nearbyint(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto rint(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::rint(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto lrint(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return quantity_t<Repr<dimensional_t<Units...>>, long>{
      std::lrint(quantity.get())};
}
template <template<class> class Repr, class T, class... Units>
auto llrint(quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  return quantity_t<Repr<dimensional_t<Units...>>, long long>{
      std::llrint(quantity.get())};
}

} // namespace mitama

#endif