#ifndef MITAMA_DIMENSIONAL_TEST_UTIL_HPP
#define MITAMA_DIMENSIONAL_TEST_UTIL_HPP

#include <type_traits>
#include <utility>
#include <tuple>
#include <random>
#include <Result.hpp>

#define IS_INVALID_EXPR(...)                                     \
  IS_INVALID_EXPR_IMPL1(__VA_ARGS__)                             \
  IS_INVALID_EXPR_IMPL2

#define IS_INVALID_EXPR_IMPL1(...) bool(false ? test_util::mitama::make_overload([](auto x)->decltype(__VA_ARGS__, std::false_type{}){return{};},[](...)->std::true_type{return{};})
#define IS_INVALID_EXPR_IMPL2(...) (::test_util::mitama::type_transfer<__VA_ARGS__>{}): ::test_util::mitama::protean_bool{})
#define DECLVAL(N) std::declval<std::tuple_element_t<N,typename decltype(x)::type>>()
#define DECLTYPE(N) std::tuple_element_t<N,typename decltype(x)::type>

namespace test_util {
  template < class ValueType >
  class RandomGenerator {
    ValueType lower, upper;
    mutable std::size_t limit;

    template < class Pred, class Dist, class Engine, std::size_t... Indices >
    static auto invoke(Pred&& pred, Dist& dist, Engine& engine, std::index_sequence<Indices...>) -> bool {
      return std::forward<Pred>(pred)((void(Indices), dist(engine))...);
    }

  public:
    RandomGenerator(ValueType a, ValueType b): lower(a), upper(b) {}

    static constexpr auto uniform(ValueType a, ValueType b) -> RandomGenerator {
      return RandomGenerator{a, b};
    }

    auto& take(std::size_t lim) {
      limit = lim;
      return *this;
    }

    template < int N = 1, class Pred >
    auto required(Pred&& pred) const -> bool {
      bool res = true;
      std::mt19937_64 mt(std::random_device{}());
      if constexpr (std::is_integral_v<ValueType>){
        std::uniform_int_distribution<ValueType> dist(lower, upper);
        while (bool(limit--) && res) {
          res = invoke(std::forward<Pred>(pred), dist, mt, std::make_index_sequence<N>{});
        }
        return res;
      }
      else if constexpr (std::is_floating_point_v<ValueType>){
        std::uniform_real_distribution<ValueType> dist(lower, upper);
        while (bool(limit--) && res) {
          res = invoke(std::forward<Pred>(pred), dist, mt, std::make_index_sequence<N>{});
        }
        return res;
      }
      else {
        return false;
      }
    }

  };
}

namespace test_util::mitama {
template <class, class = void> struct is_comparable : std::false_type {};

template <class T>
struct is_comparable<T, std::void_t<decltype(std::declval<T const &>() ==
                                             std::declval<T const &>())>>
    : std::true_type {};

template <class, class, class = void>
struct is_comparable_with : std::false_type {};

template <class T, class U>
struct is_comparable_with<T, U,
                          std::void_t<decltype(std::declval<T const &>() ==
                                               std::declval<U const &>())>>
    : std::true_type {};

struct protean_bool {
  constexpr operator std::true_type() const { return {}; }
  constexpr operator std::false_type() const { return {}; }
};

template <class T, class... Ts> struct Overload : T, Overload<Ts...> {
  Overload(T a, Ts... xs) : T{a}, Overload<Ts...>{xs...} {}
  using T::operator();
  using Overload<Ts...>::operator();
};

template <class T> struct Overload<T> : T {
  Overload(T a) : T{a} {}
  using T::operator();
};

template <class... F> inline constexpr Overload<F...> make_overload(F &&... f) {
  return {{std::forward<F>(f)}...};
}
template <class... Ts> struct type_transfer { using type = std::tuple<Ts...>; };


} // namespace mitama

namespace mitama {
template < class >
struct basis_;

template < class... Units, template < class... > class D >
struct basis_<D<Units...>>
{ template < int N > using type = typename std::tuple_element_t<N,std::tuple<Units...>>::dimension_type; };

}
#endif