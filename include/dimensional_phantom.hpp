#pragma once
#include "mitamagic/utility.hpp"
#include <type_traits>

namespace mitama::mitamagic {
template <class T> struct guardian_t { using type = T; };
template <class T, class... Types>
inline constexpr std::size_t dimension_count_v =
    (static_cast<std::size_t>(std::is_same_v<typename T::dimension_type,
                                             typename Types::dimension_type>) +
     ... + std::size_t{}); // type count meta-function
} // namespace mitama::mitamagic

namespace mitama {

template <class Dim, class Exponent> struct dimension_tag {};

template <class D, class S> struct indexed_scale_t {
  using dimension_type = D;
  using scale = S;
};
template <class... TypeIndexedScales> struct scale_storage_t {};

template <class, class> struct rescaled_ { using type = void; };

template <class D, class S1, class S2>
struct rescaled_<indexed_scale_t<D, S1>, indexed_scale_t<D, S2>> {
  using type = indexed_scale_t<D, mitamagic::ratio_min<S1, S2>>;
  using scale = std::ratio_multiply<S1, S2>;
};

template <class, class, class, class = void> struct lexical_;

template <class SP, class Head, class... Tail, class... Remainders>
struct lexical_<SP, scale_storage_t<Head, Tail...>,
                scale_storage_t<Remainders...>>
    : std::conditional_t<std::is_same_v<typename SP::dimension_type,
                                        typename Head::dimension_type>,
                         lexical_<SP, scale_storage_t<>,
                                  scale_storage_t<Remainders..., Tail...>,
                                  typename rescaled_<SP, Head>::type>,
                         lexical_<SP, scale_storage_t<Tail...>,
                                  scale_storage_t<Remainders..., Head>>> {};

template <class SP, class Inter, class... Tail, class... Remainders>
struct lexical_<SP, scale_storage_t<Tail...>, scale_storage_t<Remainders...>,
                Inter> {
  using result = scale_storage_t<Inter>;
  using remainder = scale_storage_t<Tail...>;
};

template <class SP, class... Remainders>
struct lexical_<SP, scale_storage_t<>, scale_storage_t<Remainders...>> {
  using result = scale_storage_t<SP>;
  using remainder = scale_storage_t<Remainders...>;
};

template <class, class, class> struct lexical_impl;

template <class Head, class... Tail, class... R, class... Results>
struct lexical_impl<scale_storage_t<Head, Tail...>, scale_storage_t<R...>,
                    scale_storage_t<Results...>>
    : lexical_impl<scale_storage_t<Tail...>,
                   typename lexical_<Head, scale_storage_t<R...>,
                                     scale_storage_t<>>::remainder,
                   mitamagic::tlist_cat_t<
                       scale_storage_t<Results...>,
                       typename lexical_<Head, scale_storage_t<R...>,
                                         scale_storage_t<>>::result>> {};

template <class... R, class... Results>
struct lexical_impl<scale_storage_t<>, scale_storage_t<R...>,
                    scale_storage_t<Results...>> { // inducted dimension type
  using result_type = scale_storage_t<Results..., R...>;
};

template <class, class> struct lexical_scale;

// quotient facade
template <class... ISSF1, class... ISSF2>
struct lexical_scale<scale_storage_t<ISSF1...>, scale_storage_t<ISSF2...>> {
  using type = typename lexical_impl<scale_storage_t<ISSF1...>,
                                     scale_storage_t<ISSF2...>,
                                     scale_storage_t<>>::result_type;
};

template <class L, class R>
using lexical_scale_storage_t = typename lexical_scale<L, R>::type;

template <class ScaleStorage, class... Units>
struct dimensional_t : private Units::tag... // for Dimensional tags
{
  static_assert(std::conjunction_v<std::bool_constant<
                    (mitamagic::dimension_count_v<Units, Units...> == 1)>...>,
                "same dimension is not allowed"); // sanity check
  static constexpr std::size_t value = sizeof...(Units);
};

template <class... Units>
using make_dimensional_t = dimensional_t<
    scale_storage_t<indexed_scale_t<typename Units::dimension_type,
                                    typename Units::scale>...>,
    Units...>;

template <class> struct is_dimensional : std::false_type {};
template <class S, class... Units>
struct is_dimensional<dimensional_t<S, Units...>> : std::true_type {};
template <class D>
inline constexpr bool is_dimensional_v = is_dimensional<D>::value;

} // namespace mitama