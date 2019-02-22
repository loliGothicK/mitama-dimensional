#ifndef MITAMA_DIMENSIONAL_REFINEMENT_HPP
#define MITAMA_DIMENSIONAL_REFINEMENT_HPP
#include "quantity.hpp"
#include "si/all.hpp"
namespace mitama {

namespace sym {
template <std::intmax_t N = 1> struct L {
  using basis = ::mitama::length;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct M {
  using basis = ::mitama::mass;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct T {
  using basis = ::mitama::time;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct I {
  using basis = ::mitama::electric_current;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct S {
  using basis = ::mitama::thermodynamic_temperature;
  using exp = std::ratio<N>;
};
template <std::intmax_t E = 1> struct N {
  using basis = ::mitama::amount_of_substance;
  using exp = std::ratio<E>;
};
template <std::intmax_t N = 1> struct J {
  using basis = ::mitama::luminous_intensity;
  using exp = std::ratio<N>;
};

} // namespace sym

template <class... Symbols> struct refinement_type {
  template <class Q> decltype(auto) operator()(Q &&q) const {
    static_assert(
        is_same_dimensional_v<
            std::decay_t<Q>,
            quantity<make_dimensional_t<
                units_t<typename Symbols::basis, typename Symbols::exp>...>>>,
        "refinement error: not satisfied");
    return std::forward<Q>(q);
  }
};

template <class... S> inline constexpr refinement_type<S...> refined{};
} // namespace mitama

#endif