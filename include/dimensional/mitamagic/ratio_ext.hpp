#ifndef MITAMA_DIMENSIONAL_MITAMAMAGIC_RATIO_EXT_HPP
#define MITAMA_DIMENSIONAL_MITAMAMAGIC_RATIO_EXT_HPP
#include <type_traits>
#include <ratio>

namespace mitama::mitamagic {


template <class> struct is_rational : std::false_type {};

template <std::intmax_t N, std::intmax_t D>
struct is_rational<std::ratio<N, D>> : std::true_type {};

template <class T> inline constexpr bool is_rational_v = is_rational<T>::value;

template <class R1, class R2>
using ratio_max = std::conditional_t<std::ratio_greater_v<R1, R2>, R1, R2>;

template <class R1, class R2>
using ratio_min = std::conditional_t<std::ratio_less_v<R1, R2>, R1, R2>;

}

#endif