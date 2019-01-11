#pragma once
#include "dimensional_phantom.hpp"
#include "dimensions.hpp"
#include "dimensional_traits.hpp"

namespace mitama {

template < class Dim, class T >
class quantity_t {
    T value_;
public:
    using value_type = T;
    using dimension_type = Dim;

    template<class U,
        std::enable_if_t<
            std::is_constructible_v<T, U> &&
            std::is_convertible_v<U, T>
        , bool> = false
    >
    constexpr quantity_t(U&& u): value_(std::forward<U>(u)) {}

    template<class U,
        std::enable_if_t<
            std::is_constructible_v<T, U> &&
            !std::is_convertible_v<U, T>
        , bool> = false
    >
    explicit constexpr quantity_t(U&& u) : value_(std::forward<U>(u)) {}

    template < class U, std::enable_if_t<std::is_convertible_v<U, T>, bool> = false >
    static constexpr quantity_t from_value(U&& u) { return quantity_t(std::forward<U>(u)); }
    
    T get() const { return value_; }
};

namespace mitamagic {
template < class Dim >
struct into_dimensional {
    using type = dimensional_t<units_t<Dim>>;
};

template < class... Units >
struct into_dimensional<dimensional_t<Units...>> {
    using type = dimensional_t<Units...>;
};

template < class Unit > using into_dimensional_t = typename into_dimensional<Unit>::type;
} // ! mitamagic

template < class Dim, class T >
using quantity = quantity_t<mitamagic::into_dimensional_t<Dim>, T>;

}