#ifndef MITAMA_DIMENSIONAL_MATH_NEARBYINT_HPP
#define MITAMA_DIMENSIONAL_MATH_NEARBYINT_HPP
#include <dimensional/quantity.hpp>
#include <cmath>
namespace mitama {
template <template<class> class Synonym, class T, class... Units, class S>
auto ceil(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::ceil;
  return std::decay_t<decltype(quantity)>{ceil(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto floor(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::floor;
  return std::decay_t<decltype(quantity)>{floor(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto trunc(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::trunc;
  return std::decay_t<decltype(quantity)>{trunc(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto round(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::round;
  return std::decay_t<decltype(quantity)>{round(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto lround(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::lround;
  return quantity_t<Synonym<dimensional_t<Units...>>, long>{
      lround(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto llround(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::llround;
  return quantity_t<Synonym<dimensional_t<Units...>>, long long>{
      llround(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto nearbyint(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::nearbyint;
  return std::decay_t<decltype(quantity)>{nearbyint(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto rint(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::rint;
  return std::decay_t<decltype(quantity)>{rint(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto lrint(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::lrint;
  return quantity_t<Synonym<dimensional_t<Units...>>, long>{
      lrint(quantity.value())};
}
template <template<class> class Synonym, class T, class... Units, class S>
auto llrint(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using std::llrint;
  return quantity_t<Synonym<dimensional_t<Units...>>, long long>{
      llrint(quantity.value())};
}

} // namespace mitama

#endif
