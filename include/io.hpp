#pragma once
#include <iostream>
#include <type_traits>
#include "quantity.hpp"
#include "si/meter.hpp"
#include "si/second.hpp"
#include "si/ampere.hpp"
#include "si/candela.hpp"
#include "si/kelvin.hpp"
#include "si/mol.hpp"
#include "si/kilogram.hpp"

namespace mitama {
template < class ... > inline constexpr bool abbreviation_error_v = false;
template <class T, class=void>
struct is_complete_type: std::false_type {};

template <class T>
struct is_complete_type<T,std::void_t<decltype(sizeof(T))>>
    : std::true_type {};

template < class,class = void >
struct abbreviation;

template < >
struct abbreviation<meter_t> {
    static constexpr char str[] = "m";
};
template < >
struct abbreviation<millimeter_t> {
    static constexpr char str[] = "mm";
};
template < >
struct abbreviation<centimeter_t> {
    static constexpr char str[] = "cm";
};
template < >
struct abbreviation<nanometer_t> {
    static constexpr char str[] = "nm";
};
template < >
struct abbreviation<second_t> {
    static constexpr char str[] = "s";
};
template < >
struct abbreviation<millisecond_t> {
    static constexpr char str[] = "ms";
};
template < >
struct abbreviation<nanosecond_t> {
    static constexpr char str[] = "ns";
};
template < class D >
struct abbreviation<D, std::enable_if_t<mitamagic::is_dimensionless<D>::value>> {
    static constexpr char str[] = "dimensionless";
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

template < class T, class _, class... Units>
    //,std::enable_if_t<std::conjunction_v<is_complete_type<abbreviation<typename Units::basic_type>>...>, bool> = false >
std::ostream& operator<<(std::ostream& os, quantity_t<dimensional_t<_, Units...>, T> const& quantity) {
    if constexpr (is_complete_type<abbreviation<dimensional_t<_, Units...>>>::value){
        return os << quantity.get() << "[ " << abbreviation<dimensional_t<_, Units...>>::str << " ]";
    }
    else if constexpr (std::conjunction_v<is_complete_type<abbreviation<dimensional_t<_, typename Units::basic_type>>>...>) {
        os << quantity.get() << "[ ";
        ((
            os << abbreviation<dimensional_t<_, typename Units::basic_type>>::str << exponent<typename Units::exponent> << " "
        ), ...);
        return os << "]";
    }
    else {
        static_assert(abbreviation_error_v<dimensional_t<_, Units...>>);
    }
}

}