#pragma once
#include "quotient.hpp"


namespace mitama {
template < class Dim, class T = double >
class quantity_t;

// meta-operator for dimension equivalence
// primary template
template < class, class >
struct is_same_dimensional: std::false_type {};

// meta-operator for dimension equivalence
// template partial specialization for dimensional_t
template < class T, class U, class S1, class S2, class... Units1, class... Units2 >
struct is_same_dimensional<quantity_t<dimensional_t<S1, Units1...>, T>, quantity_t<dimensional_t<S2, Units2...>, U>>
    : std::conjunction<std::bool_constant<sizeof...(Units1) == sizeof...(Units2)>, std::is_base_of<typename Units1::tag, dimensional_t<S2, Units2...>>...>
{};

// alias variable template
template < class L, class R >
inline constexpr bool is_same_dimensional_v = is_same_dimensional<L, R>::value;

}


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

    template < class D, class U,
        std::enable_if_t<
            is_same_dimensional_v<quantity_t, quantity_t<D, U>> &&
            std::is_constructible_v<T, U> &&
            std::is_convertible_v<U, T>
        , bool> = false
    >
    constexpr quantity_t(quantity_t<D, U> const& o): value_(mitamagic::converted_value<quantity_t>(o)) {}

    template < class D, class U,
        std::enable_if_t<
            is_same_dimensional_v<quantity_t, quantity_t<D, U>> &&
            std::is_constructible_v<T, U> &&
            !std::is_convertible_v<U, T>
        , bool> = false
    >
    explicit constexpr quantity_t(quantity_t<Dim, U> const& o): value_(mitamagic::converted_value<quantity_t>(o)) {}

    template < class D, class U,
        std::enable_if_t<
            is_same_dimensional_v<quantity_t, quantity_t<D, U>> &&
            std::is_convertible_v<U, T>
        , bool> = false
    >
    constexpr quantity_t& operator=(quantity_t<Dim, U> const& o) & {
        this->value_ = mitamagic::converted_value<quantity_t>(o);
        return *this;
    }
    
    constexpr T get() const { return value_; }
};

namespace mitamagic {
template < class Dim >
struct into_dimensional {
    using type = dimensional_t<units_t<Dim>>;
};

template < class Dim >
struct into_dimensional<units_t<Dim>> {
    using type = dimensional_t<units_t<Dim>>;
};


template < class... Units >
struct into_dimensional<dimensional_t<Units...>> {
    using type = dimensional_t<Units...>;
};

template < class Unit > using into_dimensional_t = typename into_dimensional<Unit>::type;
} // ! mitamagic

template < class Dim, class T = double >
using quantity = quantity_t<mitamagic::into_dimensional_t<Dim>, T>;

template < class T >
struct is_quantity: std::false_type {};

template < class D, class T >
struct is_quantity<quantity_t<D, T>>: std::true_type {};

template < class T >
inline constexpr bool is_quantity_v = is_quantity<T>::value;
}


namespace mitama {
template < class U1, class U2, std::enable_if_t<is_dimensional_v<U1> && is_dimensional_v<U2>, bool> = false >
constexpr mitamagic::quotient_t<mitamagic::into_dimensional_t<U1>, mitamagic::into_dimensional_t<U2>>
operator*(U1, U2) {
    return {};
}

template < class U1, class U2, std::enable_if_t<is_dimensional_v<U1> && is_dimensional_v<U2>, bool> = false >
constexpr mitamagic::quotient_t<mitamagic::into_dimensional_t<U1>, mitamagic::inverse_t<mitamagic::into_dimensional_t<U2>>>
operator/(U1, U2) {
    return {};
}

template < std::intmax_t N, class U, std::enable_if_t<is_dimensional_v<U>, bool> = false >
constexpr typename mitamagic::powered_dimensional<U, N>::type
pow(U) {
    return {};
}

template < class Dim, class T >
constexpr std::enable_if_t<is_dimensional_v<Dim>, quantity_t<Dim, T>>
operator|(T&& t, Dim) {
    return {std::forward<T>(t)};
}
}


namespace mitama{
template < class To, class From, std::enable_if_t<is_same_dimensional_v<To, std::decay_t<From>>, bool> = false >
inline constexpr From scale_cast(From&& from)
{
    
}


}