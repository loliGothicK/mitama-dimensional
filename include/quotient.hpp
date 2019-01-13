#pragma once
#include <type_traits>
#include <ratio>
#include <utility>
#include <cmath>
#include "units.hpp"
#include "dimensional_phantom.hpp"
#include "dimensional_traits.hpp"
#include <tuple>
#include <variant>

// Type List Modules
namespace mitama::mitamagic {
    template < class R1, class R2 >
    using ratio_max = std::conditional_t<std::ratio_greater_v<R1, R2>, R1, R2>;

    template < class R1, class R2 >
    using ratio_min = std::conditional_t<std::ratio_less_v<R1, R2>, R1, R2>;

    template < class ... >
    struct type_list {}; // Type List
    
    template <class...> struct tlist_cat; // List concatenate: primary

    template <template <class...> class Pack, class... Left, class... Right>
    struct tlist_cat<Pack<Left...>, Pack<Right...>>
        { using type = Pack<Left..., Right...>; }; // List concatenate: binary

    template <class Pack1st, class Pack2nd, class... PackTail>
    struct tlist_cat<Pack1st, Pack2nd, PackTail...>
        : tlist_cat<typename tlist_cat<Pack1st, Pack2nd>::type, PackTail...>
    {};  // List concatenate: variadic(recursive class)

    template <class... Packs> using tlist_cat_t = typename tlist_cat<Packs...>::type; // alias template

    template <std::size_t I, class T> struct tlist_element;

    // recursive case
    template <std::size_t I, template <class...> class Pack, class Head,
            class... Tail>
    struct tlist_element<I, Pack<Head, Tail...>>
        : tlist_element<I - 1, Pack<Tail...>>
        { static_assert(I <= sizeof...(Tail), "pack out of range."); };

    // base case
    template <template <class...> class Pack, class Head, class... Tail>
    struct tlist_element<0, Pack<Head, Tail...>>
        { using type = Head; };

    template <size_t N, typename Pack>
    using tlist_element_t = typename tlist_element<N, Pack>::type;
} // ! mitamagic


namespace mitama::mitamagic {
template < class , class > struct prod;

template < class D, class Exp1, class Exp2, class S1, class S2 >
struct prod<units_t<D, Exp1, S1>, units_t<D, Exp2, S2>>
{
    using type = type_list<Exp1, S1, Exp2, S2>;
};
template < class, class > struct scaler;

template < class U, class Head, class... Tail >
struct find_if: std::conditional_t<
    std::is_same_v<typename U::tag, typename Head::tag>,
    prod<U, Head>,
    find_if<U, Tail...>
>
{};

template < class U, class H >
struct find_if<U, H> {
    using type = std::conditional_t<
        std::is_same_v<typename U::tag, typename H::tag>,
        typename prod<U, H>::type,
        type_list<>>;
};

template < class... U1, class... U2 >
struct scaler<dimensional_t<U1...>, dimensional_t<U2...>> {
    template <class R1, class R2>
    static long double convert(){
        return std::pow(
                static_cast<long double>(R1::num) / static_cast<long double>(R1::den),
                static_cast<long double>(R2::num) / static_cast<long double>(R2::den));
    }

    template < class T, class... Seq >
    static constexpr auto eval() {
        auto c = ((convert<tlist_element_t<1,Seq>, tlist_element_t<0,Seq>>() / convert<tlist_element_t<3,Seq>, tlist_element_t<2,Seq>>()) * ... * 1.0l);
        return c < 1.0l ? std::tuple{false, static_cast<T>(1.0l/c)} : std::tuple{true, static_cast<T>(c)};
    }
    template < class T >
    static constexpr auto value() {
        return eval<T, typename find_if<U1, U2...>::type...>();
    }
};

template <class Q1, class Q2, class F>
constexpr auto scaled_value(Q1&& q1, Q2&& q2, F&& f){
    using lhs_t = std::decay_t<Q1>;
    using rhs_t = std::decay_t<Q2>;
    using common_t = std::common_type_t<typename lhs_t::value_type, typename rhs_t::value_type>;
    if (auto [flag, c] = scaler<typename lhs_t::dimension_type, typename rhs_t::dimension_type>::template value<common_t>(); flag)
    {
        return std::forward<F>(f)(std::forward<Q1>(q1).get() * c, std::forward<Q2>(q2).get());
    }
    else
    {
        return std::forward<F>(f)(std::forward<Q1>(q1).get(), std::forward<Q2>(q2).get() * c);
    }
}

template <class To, class From>
constexpr auto converted_value(From&& quantity){
    return std::forward<From>(quantity).get() * std::get<1>(scaler<typename To::dimension_type, typename std::decay_t<From>::dimension_type>::template value<typename To::value_type>());
}


template < class, class, class >
struct scaled_demension;

template < class... L, class... R, std::size_t... I>
struct scaled_demension<dimensional_t<L...>, dimensional_t<R...>, std::index_sequence<I...>>{
    using type = dimensional_t<
        units_t<
            typename tlist_element_t<I, type_list<L...>>::dimension_type,
            typename tlist_element_t<I, type_list<L...>>::exponent,
            ratio_min<typename tlist_element_t<I, type_list<L...>>::scale, typename tlist_element_t<I, type_list<R...>>::scale>
        >...
    >;
};

template < class L, class R >
using scaled_demension_t = typename scaled_demension<L, R, std::make_index_sequence<L::value>>::type;
}


namespace mitama::mitamagic{
// dimension exponent inverse implementation
template < class > struct inversed;

template < class Dim, std::intmax_t N, std::intmax_t D, class S >
struct inversed<units_t<Dim, std::ratio<N, D>, S>>
    { using type = units_t<Dim, std::ratio_multiply<std::ratio<N,D>, std::ratio<-1>>, S>; };

// meta-function for dimension exponent inverse
// primary template
template < class >
struct inverse;

// meta-function for dimension exponent inverse
// partial template specialization
template < class... Units >
struct inverse<dimensional_t<Units...>>
{   // invoke to mitamagic::inversed
using type = dimensional_t<typename mitamagic::inversed<Units>::type...>;
};

// alias template for inverse
template < class T > using inverse_t = typename inverse<T>::type;

struct dimensionless;

// meta-operator for product with two same dimensions
// parimary template
template < class , class > struct product;

// meta-operator for product with two same dimensions
// partial template specialization for phantom_t
template < class D, class Exp1, class Exp2, class S1, class S2 >
struct product<units_t<D, Exp1, S1>, units_t<D, Exp2, S2>>
{
    using type = std::conditional_t<
                    std::ratio_equal_v<std::ratio_add<Exp1, Exp2>, std::ratio<0>>,
                        dimensionless,
                        units_t<D, std::ratio_add<Exp1, Exp2>, ratio_min<S1, S2>>
                >;
};

// Induction-Sweeper
// parimary template
template < class, class, class, class > struct quotient_;

// Induction-Sweeper
// recursive template guardian
template < class T, class... Result, class... Remainders >
struct quotient_<T, type_list<>, type_list<Remainders...>, type_list<Result...>>
{
    using result = type_list<Result...>;
    using remainder = type_list<Remainders...>;
};

// Induction-Sweeper
// recursive template guardian    
template < class T, class Head, class... Tail, class... Remainders, class... Results >
struct quotient_<T, type_list<Head, Tail...>, type_list<Remainders...>, type_list<Results...>>
    : std::conditional_t<
        // if: << has same dimension? >>
        std::is_same_v<typename T::dimension_type, typename Head::dimension_type>,
        // then => calc dimension
        quotient_<T, type_list<>, type_list<Remainders..., Tail...>, 
                std::conditional_t</* if: << into dimensionless? >> */ std::is_same_v<dimensionless,typename product<T, Head>::type>,
                                    /* thne => remove                */ type_list<Results...>,
                                    /* else => add to result         */ type_list<Results..., typename product<T, Head>::type> >>,
        // else => keep Head to remain
        quotient_<T, type_list<Tail...>, type_list<Remainders..., Head>, type_list<Results...>>
    >
{
};

// magical quotient type for induction new dimension combination
// parimary template
template < class, class, class > struct quotient_impl;

// magical quotient type for induction new dimension type
// recursive partial template specialization
template < class Head, class... Tail, class... R, class... Results >
struct quotient_impl<type_list<Head, Tail...>, type_list<R...>, type_list<Results...>>
    : quotient_impl<
        type_list<Tail...>,
        typename quotient_< Head, type_list<R...>, type_list<>, type_list<Results...> >::remainder,
        tlist_cat_t<type_list<Results...>, typename quotient_< Head, type_list<R...>, type_list<>, type_list<Results...> >::result>
    >
{
};

// magical quotient type for induction new dimension type
// recursive partial template specialization guardian
template < class... R, class... Results >
struct quotient_impl<type_list<>, type_list<R...>, type_list<Results...>>
{   // inducted dimension type
    using result_type = dimensional_t<Results..., R...>;
};

// quotient facade
// Quotient = Dim -> Dim -> Dim
template < class, class > struct quotient;

// quotient facade
template < class... LeftPhantomTypes, class... RightPhantomTypes >
struct quotient<dimensional_t<LeftPhantomTypes...>, dimensional_t<RightPhantomTypes...>>
{
    using type = typename mitamagic::quotient_impl<mitamagic::type_list<LeftPhantomTypes...>, mitamagic::type_list<RightPhantomTypes...>, mitamagic::type_list<>>::result_type;
};
template <class,std::intmax_t> struct powered_dimensional;
template < std::intmax_t N, class... PhantomTypes >
struct powered_dimensional<dimensional_t<PhantomTypes...>, N>
{
    using type = dimensional_t<units_t<typename PhantomTypes::dimension_type, std::ratio_multiply<typename PhantomTypes::exponent, std::ratio<N>>, typename PhantomTypes::scale>...>;
};


template < class L, class R > using quotient_t = typename quotient<L, R>::type;
}