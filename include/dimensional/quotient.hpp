#ifndef MITAMA_DIMENSIONAL_QUOTIENT_HPP
#define MITAMA_DIMENSIONAL_QUOTIENT_HPP
#include "dimensional_phantom.hpp"
#include "mitamagic/utility.hpp"
#include "units.hpp"
#include <cmath>
#include <iostream>
#include <ratio>
#include <tuple>
#include <type_traits>
#include <utility>

namespace mitama {

template <class... Tags> struct dimensionless {
  using dimension_type = dimensionless<>;
  using exponent = std::ratio<1>;
  using scale = std::ratio<1>;
  using tag = dimensionless<Tags...>;
  using basic_type = dimensionless<Tags...>;
  using is_base_dimension = void;
};
template <class D, class E> struct dimensionless<D, E> {
  using tag = dimension_tag<D, E>;
};
template <class> struct is_dimensionless_type : std::false_type {};
template <class... Tags>
struct is_dimensionless_type<dimensionless<Tags...>> : std::true_type {};
} // namespace mitama

namespace mitama::mitamagic {
template <class, class> struct prod { using type = void; };

template <class D, class Exp1, class Exp2, class S1, class S2>
struct prod<units_t<D, Exp1, S1>, units_t<D, Exp2, S2>> {
  using type = type_list<Exp1, S1, Exp2, S2>;
};
template <class, class> struct scaler;

template <class U, class Head, class... Tail>
struct find_if
    : std::conditional_t<std::is_same_v<typename U::dimension_type,
                                        typename Head::dimension_type>,
                         prod<U, Head>, find_if<U, Tail...>> {};

using not_found =
    type_list<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>;

template <class U, class H> struct find_if<U, H> {
  using type = std::conditional_t<
      std::is_same_v<typename U::dimension_type, typename H::dimension_type>,
      typename prod<U, H>::type, not_found>;
};

template <class... U1, class... U2>
struct scaler<dimensional_t<U1...>, dimensional_t<U2...>> {
  template <class R1, class R2> static constexpr long double convert() {
    return std::pow(
        static_cast<long double>(R1::num) / static_cast<long double>(R1::den),
        static_cast<long double>(R2::num) / static_cast<long double>(R2::den));
  }

  template <class T, class... Seq> static constexpr auto eval() {
    long double left = 1.0l;
    long double right = 1.0l;
    (((std::ratio_less_v<tlist_element_t<1, Seq>, tlist_element_t<3, Seq>>)
          ? (right *= convert<std::ratio_divide<tlist_element_t<3, Seq>,
                                                tlist_element_t<1, Seq>>,
                              tlist_element_t<2, Seq>>())
          : (left *= convert<std::ratio_divide<tlist_element_t<1, Seq>,
                                               tlist_element_t<3, Seq>>,
                             tlist_element_t<0, Seq>>())),
     ...);
    return std::tuple{static_cast<T>(left), static_cast<T>(right)};
  }
  template <class T> static constexpr auto value() {
    return eval<T, typename find_if<U1, U2...>::type...>();
  }

  template <class T, class... Seq> static constexpr auto cast() {
    long double value = 1.0l;
    ((value *= convert<
          std::ratio_divide<tlist_element_t<3, Seq>, tlist_element_t<1, Seq>>,
          tlist_element_t<2, Seq>>()),
     ...);
    return value;
  }

  template <class T> static constexpr auto cast_coefficient() {
    return cast<T, typename find_if<U1, U2...>::type...>();
  }
};

template <class Q1, class Q2, class F>
constexpr auto scaled_value(Q1 &&q1, Q2 &&q2, F &&f) {
  using lhs_t = std::decay_t<Q1>;
  using rhs_t = std::decay_t<Q2>;
  using common_t = std::common_type_t<typename lhs_t::value_type,
                                      typename rhs_t::value_type>;
  auto [l, r] =
      scaler<typename lhs_t::dimension_type,
             typename rhs_t::dimension_type>::template value<common_t>();
  return std::forward<F>(f)(std::forward<Q1>(q1).get() * l,
                            std::forward<Q2>(q2).get() * r);
}

template <class To, class From>
constexpr auto converted_value(From &&quantity) {
  return std::forward<From>(quantity).get() *
         scaler<typename To::dimension_type,
                typename std::decay_t<From>::dimension_type>::
             template cast_coefficient<typename To::value_type>();
}

template <class, class, class> struct scaled_demension;

template <class... L, class... R,
          std::size_t... I>
struct scaled_demension<dimensional_t<L...>,
                        dimensional_t<R...>,
                        std::index_sequence<I...>> {
  using type = dimensional_t<
      units_t<
          typename tlist_element_t<I, type_list<L...>>::dimension_type,
          typename tlist_element_t<I, type_list<L...>>::exponent,
          ratio_min<typename tlist_element_t<I, type_list<L...>>::scale,
                    typename tlist_element_t<I, type_list<R...>>::scale>>...>;
};

template <class L, class R>
using scaled_demension_t =
    typename scaled_demension<L, R, std::make_index_sequence<L::value>>::type;
} // namespace mitama::mitamagic

namespace mitama::mitamagic {
// dimension exponent inverse implementation
template <class> struct inversed;

template <class Dim, std::intmax_t N, std::intmax_t D, class S>
struct inversed<units_t<Dim, std::ratio<N, D>, S>> {
  using type =
      units_t<Dim, std::ratio_multiply<std::ratio<N, D>, std::ratio<-1>>, S>;
};

// meta-function for dimension exponent inverse
// primary template
template <class> struct inverse;

// meta-function for dimension exponent inverse
// partial template specialization
template <class... Units>
struct inverse<dimensional_t<Units...>> { // invoke to mitamagic::inversed
  using type = dimensional_t<typename mitamagic::inversed<Units>::type...>;
};

// alias template for inverse
template <class T> using inverse_t = typename inverse<T>::type;

// meta-operator for reduce with two same dimensions
// parimary template
template <class, class> struct reduce { using type = void; };

// meta-operator for reduce with two same dimensions
// partial template specialization for phantom_t
template <class D, class Exp1, class Exp2, class S1, class S2>
struct reduce<units_t<D, Exp1, S1>, units_t<D, Exp2, S2>> {
  using type = std::conditional_t<
      std::ratio_equal_v<std::ratio_add<Exp1, Exp2>, std::ratio<0>>,
      dimensionless<dimension_tag<D, ratio_max<Exp1, Exp2>>>,
      units_t<D, std::ratio_add<Exp1, Exp2>, ratio_min<S1, S2>>>;
};

template <class, class, class, class = void> struct quotient_;

template <class SP, class Head, class... Tail, class... Remainders>
struct quotient_<SP, type_list<Head, Tail...>,
                type_list<Remainders...>>
    : std::conditional_t<std::is_same_v<typename SP::dimension_type,
                                        typename Head::dimension_type>,
                         quotient_<SP, type_list<>,
                                  type_list<Remainders..., Tail...>,
                                  typename reduce<SP, Head>::type>,
                         quotient_<SP, type_list<Tail...>,
                                  type_list<Remainders..., Head>>> {};

template <class SP, class Inter, class... Tail, class... Remainders>
struct quotient_<SP, type_list<Tail...>, type_list<Remainders...>,
                Inter> {
  using result = type_list<Inter>;
  using remainder = type_list<Tail..., Remainders...>;
};

template <class SP, class... Remainders>
struct quotient_<SP, type_list<>, type_list<Remainders...>> {
  using result = type_list<SP>;
  using remainder = type_list<Remainders...>;
};

template <class, class, class> struct quotient_impl;

template <class Head, class... Tail, class... R, class... Results>
struct quotient_impl<type_list<Head, Tail...>, type_list<R...>, type_list<Results...>>
    : quotient_impl<type_list<Tail...>,
                    typename quotient_<Head, type_list<R...>,
                                       type_list<>>::remainder,
                    mitamagic::tlist_cat_t<
                        type_list<Results...>,
                        typename quotient_<Head, type_list<R...>,
                                           type_list<>>::result>> {};

template <class... R, class... Results>
struct quotient_impl<type_list<>, type_list<R...>, type_list<Results...>> {
  using result_type = dimensional_t<Results..., R...>;
};

// quotient facade
// Quotient = Dim -> Dim -> Dim
template <class, class> struct quotient;

// quotient facade
template <class... LeftPhantomTypes,
          class... RightPhantomTypes>
struct quotient<dimensional_t<LeftPhantomTypes...>,
                dimensional_t<RightPhantomTypes...>> {
  using type = 
    mitamagic::tlist_remove_if_t<
      is_dimensionless_type,
      typename mitamagic::quotient_impl<
        mitamagic::type_list<LeftPhantomTypes...>,
        mitamagic::type_list<RightPhantomTypes...>,
        mitamagic::type_list<>
      >::result_type>;
};

template <class, class> struct powered_dimensional;

template <std::intmax_t N, std::intmax_t D, class... PhantomTypes>
struct powered_dimensional<dimensional_t<PhantomTypes...>,
                           std::ratio<N, D>> {
  using type =
      dimensional_t<units_t<typename PhantomTypes::dimension_type,
                            std::ratio_multiply<typename PhantomTypes::exponent,
                                                std::ratio<N, D>>,
                            typename PhantomTypes::scale>...>;
};

template <class L, class R> using quotient_t = typename quotient<L, R>::type;
} // namespace mitama::mitamagic

namespace mitama {

template <class U, std::intmax_t N>
using powered_t =
    typename mitamagic::powered_dimensional<U, std::ratio<N>>::type;

template < class U >
using reciprocal_t = powered_t<U, -1>;

}


namespace mitama::mitamagic {
template <class> struct is_dimensionless : std::false_type {};
template <class... Tags>
struct is_dimensionless<dimensional_t<dimensionless<Tags...>>>
    : std::true_type {};
} // namespace mitama::mitamagic
#endif