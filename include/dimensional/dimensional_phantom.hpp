#ifndef MITAMA_DIMENSIONAL_PHANTOM_HPP
#define MITAMA_DIMENSIONAL_PHANTOM_HPP
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

template <class... Units>
struct dimensional_t : private Units::tag... // for Dimensional tags
{
  static_assert(std::conjunction_v<std::bool_constant<
                    (mitamagic::dimension_count_v<Units, Units...> == 1)>...>,
                "same dimension is not allowed"); // sanity check
  static constexpr std::size_t value = sizeof...(Units);
};

template <class... Units>
using make_dimensional_t = dimensional_t<Units...>;

template <class> struct is_dimensional : std::false_type {};
template <class... Units>
struct is_dimensional<dimensional_t<Units...>> : std::true_type {};
template <class D>
inline constexpr bool is_dimensional_v = is_dimensional<D>::value;

} // namespace mitama
#endif