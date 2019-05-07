#ifndef MITAMA_DIMENSIONAL_MATH_NEARBYINT_HPP
#define MITAMA_DIMENSIONAL_MATH_NEARBYINT_HPP
#include "../quantity.hpp"
#include <cmath>
namespace mitama {
template <template<class> class Synonym, class T, class... Units>
auto ceil(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::ceil(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto floor(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::floor(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto trunc(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::trunc(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto round(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::round(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto lround(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return quantity_t<Synonym<dimensional_t<Units...>>, long>{
      std::round(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto llround(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return quantity_t<Synonym<dimensional_t<Units...>>, long long>{
      std::round(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto nearbyint(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::nearbyint(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto rint(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return std::decay_t<decltype(quantity)>{std::rint(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto lrint(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return quantity_t<Synonym<dimensional_t<Units...>>, long>{
      std::lrint(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units>
auto llrint(quantity_t<Synonym<dimensional_t<Units...>>, T> const &quantity) {
  return quantity_t<Synonym<dimensional_t<Units...>>, long long>{
      std::llrint(quantity.value())};
}

} // namespace mitama

#endif