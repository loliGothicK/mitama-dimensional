#ifndef MITAMA_DIMENSIONAL_MATH_TRIGONOMETRIC_HPP
#define MITAMA_DIMENSIONAL_MATH_TRIGONOMETRIC_HPP

#include "../derived_units/named_units.hpp"
#include <cmath>

namespace mitama {
    template < class T >
    auto sin(quantity<si::radian_t, T> const& rad) {
        return std::sin(rad.get());
    }
    template < class T >
    auto cos(quantity<si::radian_t, T> const& rad) {
        return std::cos(rad.get());
    }
    template < class T >
    auto tan(quantity<si::radian_t, T> const& rad) {
        return std::tan(rad.get());
    }
    template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
    auto asin(T const& v) {
        return std::asin(v) | si::radian;
    }
    template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
    auto acos(T const& v) {
        return std::acos(v) | si::radian;
    }
    template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
    auto atan(T const& v) {
        return std::atan(v) | si::radian;
    }

}

#endif
