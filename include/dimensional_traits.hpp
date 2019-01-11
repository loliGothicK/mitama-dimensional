#pragma once
#include <type_traits>

namespace mitama {
template < class Dim, class T > class quantity_t;
template <class...> struct dimensional_t;

// meta-operator for dimension equivalence
// primary template
template < class, class >
struct is_same_dimensional: std::false_type {};

// meta-operator for dimension equivalence
// template partial specialization for dimensional_t
template < class T, class U, class... Units1, class... Units2 >
struct is_same_dimensional<quantity_t<dimensional_t<Units1...>, T>, quantity_t<dimensional_t<Units2...>, U>>
    : std::conjunction<std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>, std::is_base_of<typename Units1::tag, dimensional_t<Units2...>>...>
{};

// alias variable template
template < class L, class R >
inline constexpr bool is_same_dimensional_v = is_same_dimensional<L, R>::value;

}