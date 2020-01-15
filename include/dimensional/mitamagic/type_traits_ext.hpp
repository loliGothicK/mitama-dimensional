#ifndef MITAMA_DIMENSIONAL_MITAMAMAGIC_TYPE_TRAITS_EXT_HPP
#define MITAMA_DIMENSIONAL_MITAMAMAGIC_TYPE_TRAITS_EXT_HPP
#include <type_traits>
#include <utility>

namespace mitama {

template < class T > struct identity: T { using type = T; };
template < class T > using identity_t = typename identity<T>::type;

template < class... > inline constexpr bool always_false_v = false;

template <class T, class = void> struct is_complete_type : std::false_type {};

template <class T>
struct is_complete_type<T, std::void_t<decltype(sizeof(T))>> : std::true_type {};

template <class T> inline constexpr bool is_complete_type_v = is_complete_type<T>::value;

template < class, class, class = void >
struct is_greater_comparable_with: std::false_type {};

template < class T, class U >
struct is_greater_comparable_with<T, U, std::void_t<decltype(std::declval<T const&>() > std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_greater_comparable = is_greater_comparable_with<T, T>;

template < class, class, class = void >
struct is_less_or_equal_comparable_with: std::false_type {};

template < class T, class U >
struct is_less_or_equal_comparable_with<T, U, std::void_t<decltype(std::declval<T const&>() <= std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_less_or_equal_comparable = is_less_or_equal_comparable_with<T, T>;

template < class, class, class = void >
struct is_greater_or_equal_comparable_with: std::false_type {};

template < class T, class U >
struct is_greater_or_equal_comparable_with<T, U, std::void_t<decltype(std::declval<T const&>() >= std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_greater_or_equal_comparable = is_greater_or_equal_comparable_with<T, T>;

template < class, class, class = void >
struct is_equal_comparable_with: std::false_type {};

template < class T, class U >
struct is_equal_comparable_with<T, U, std::void_t<decltype(std::declval<T const&>() == std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_equal_comparable = is_equal_comparable_with<T, T>;

template < class, class, class = void >
struct is_notequal_comparable_with: std::false_type {};

template < class T, class U >
struct is_notequal_comparable_with<T, U, std::void_t<decltype(std::declval<T const&>() != std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_notequal_comparable = is_notequal_comparable_with<T, T>;

template < class, class, class = void >
struct is_addable_with: std::false_type {};

template < class T, class U >
struct is_addable_with<T, U, std::void_t<decltype(std::declval<T const&>() + std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_addable = is_addable_with<T, T>;

template < class T, class U >
inline constexpr bool is_addable_with_v = is_addable_with<T, U>::value;

template < class T >
inline constexpr bool is_addable_v = is_addable<T>::value;

template < class, class, class = void >
struct is_subtractible_with: std::false_type {};

template < class T, class U >
struct is_subtractible_with<T, U, std::void_t<decltype(std::declval<T const&>() - std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_subtractible = is_subtractible_with<T, T>;

template < class T, class U >
inline constexpr bool is_subtractible_with_v = is_subtractible_with<T, U>::value;

template < class T >
inline constexpr bool is_subtractible_v = is_subtractible<T>::value;

template < class, class, class = void >
struct is_multipliable_with: std::false_type {};

template < class T, class U >
struct is_multipliable_with<T, U, std::void_t<decltype(std::declval<T const&>() * std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_multipliable = is_multipliable_with<T, T>;

template < class T, class U >
inline constexpr bool is_multipliable_with_v = is_multipliable_with<T, U>::value;

template < class T >
inline constexpr bool is_multipliable_v = is_multipliable<T>::value;

template < class, class, class = void >
struct is_dividable_with: std::false_type {};

template < class T, class U >
struct is_dividable_with<T, U, std::void_t<decltype(std::declval<T const&>() / std::declval<U const&>())>>: std::true_type {};

template < class T >
using is_dividable = is_dividable_with<T, T>;

template < class T, class U >
inline constexpr bool is_dividable_with_v = is_dividable_with<T, U>::value;

template < class T >
inline constexpr bool is_dividable_v = is_dividable<T>::value;
}

#endif