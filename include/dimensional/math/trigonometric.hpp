#ifndef MITAMA_DIMENSIONAL_MATH_TRIGONOMETRIC_HPP
#define MITAMA_DIMENSIONAL_MATH_TRIGONOMETRIC_HPP

#include <dimensional/systems/si/derived_units/angle.hpp>
#include <cmath>

namespace mitama {
    template < class T, class S >
    auto sin(quantity_t<systems::si::radian_t, T, S> const& rad) {
        return std::sin(rad.value());
    }
    template < class T, class S >
    auto cos(quantity_t<systems::si::radian_t, T, S> const& rad) {
        return std::cos(rad.value());
    }
    template < class T, class S >
    auto tan(quantity_t<systems::si::radian_t, T, S> const& rad) {
        return std::tan(rad.value());
    }
    template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
    auto asin(T const& v) {
        return std::asin(v) | systems::si::radian;
    }
    template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
    auto acos(T const& v) {
        return std::acos(v) | systems::si::radian;
    }
    template < class T, std::enable_if_t<!is_quantity_v<T>, bool> = false>
    auto atan(T const& v) {
        return std::atan(v) | systems::si::radian;
    }

}

#endif
