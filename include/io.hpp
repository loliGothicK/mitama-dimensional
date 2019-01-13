#pragma once
#include <iostream>
#include <type_traits>
#include "quantity.hpp"
#include "si/meters.hpp"
namespace mitama {
template < class ... > inline constexpr bool abbreviation_error_v = false;
template <class T, class=void>
struct is_complete_type: std::false_type {};

template <class T>
struct is_complete_type<T,std::void_t<decltype(sizeof(T))>>
    : std::true_type {};


template < class >
struct abbreviation;

template < >
struct abbreviation<meters_t> {
    static constexpr char str[] = "m";
};
template < >
struct abbreviation<millimeters_t> {
    static constexpr char str[] = "mm";
};

template < class E >
inline std::string exponent = []{
    using namespace std::literals;
    if constexpr (std::ratio_equal_v<E, std::ratio<1>>)
        return "";
    else if constexpr (E::den == 1)
        return "^"s + std::to_string(E::num);
    else
        return "^("s + std::to_string(E::num) + "/" + std::to_string(E::den) + ")";
}();

template < class T, class... Units>
    //,std::enable_if_t<std::conjunction_v<is_complete_type<abbreviation<typename Units::basic_type>>...>, bool> = false >
std::ostream& operator<<(std::ostream& os, quantity_t<dimensional_t<Units...>, T> const& quantity) {
    if constexpr (is_complete_type<abbreviation<dimensional_t<Units...>>>::value){
        os << "[ " << abbreviation<dimensional_t<Units...>>::str << " ]";
    }
    else if constexpr (std::conjunction_v<is_complete_type<abbreviation<dimensional_t<typename Units::basic_type>>>...>) {
        os << quantity.get() << "[ ";
        ((
            os << abbreviation<dimensional_t<typename Units::basic_type>>::str << exponent<typename Units::exponent> << " "
        ), ...);
        return os << "]";
    }
    else {
        static_assert(abbreviation_error_v<dimensional_t<Units...>>);
    }
}

}