#ifndef MITAMA_DIMENSIONAL_HPP
#define MITAMA_DIMENSIONAL_HPP
#include <dimensional/fwd/dimensional_fwd.hpp>
#include <dimensional/fwd/system.hpp>
#include <dimensional/mitamagic/utility_ext.hpp>
#include <dimensional/mitamagic/type_traits_ext.hpp>
#include <dimensional/mitamagic/ratio_ext.hpp>
#include <dimensional/mitamagic/type_list.hpp>
#include <type_traits>

namespace mitama::mitamagic {
template <class T, class... Types>
inline constexpr std::size_t dimension_count_v =
    (static_cast<std::size_t>(std::is_same_v<typename T::dimension_type,
                                             typename Types::dimension_type>) +
     ... + std::size_t{}); // type count meta-function
} // namespace mitama::mitamagic

namespace mitama {

template < class >
struct si_base_units {};

template <int I, class Dim, class Exponent> struct dimension_tag {};

template <class... Units>
struct dimensional_t : private Units::tag... // for Dimensional tags
{
  template < class T >
  struct is_wildcard : std::is_same<T, system<>> {};
  // sanity check for duplicate
  static_assert(std::conjunction_v<std::bool_constant<
                    (mitamagic::dimension_count_v<Units, Units...> == 1)>...>,
                "same dimension is not allowed");
   // sanity check for system
   static_assert(mitamagic::tlist_all_same_v<
                  mitamagic::tlist_remove_if_t<is_wildcard,
                    mitamagic::type_list<typename Units::system_type...>>>,
                "different units within a dimension");
  static constexpr std::size_t value = sizeof...(Units);
};

template <class... Units>
using make_dimensional_t = si_base_units<dimensional_t<Units...>>;


} // namespace mitama
#endif
