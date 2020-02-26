#ifndef MITAMA_DIMENSIONAL_MITAMAGIC_CHARS_TO_DECIMAL_HPP
#define MITAMA_DIMENSIONAL_MITAMAGIC_CHARS_TO_DECIMAL_HPP
#include <type_traits>
#include <utility>

namespace mitama::mitamagic {
  template < std::size_t, class > struct Exp10;
  template < std::size_t E, std::size_t... I >
	struct Exp10<E, std::index_sequence<I...>> : std::integral_constant<std::size_t, E * (1 * ... * ((void)I,10))> {};
	
	template < char Head, char... Digits >
	struct into_decimal
		: std::integral_constant<
        std::size_t,
        Exp10<(Head - '0'), std::make_index_sequence<sizeof...(Digits)>>::value
      + into_decimal<Digits...>::value >
  {
    static_assert(
      ( ('0' <= Head && Head <= '9') && ... && ('0' <= Digits && Digits <= '9') ),
      "Error");
  };
	
	template < char Head >
	struct into_decimal<Head>
		: std::integral_constant<std::size_t, Head-'0'> {};

  template < char... Digits >
  inline constexpr std::size_t into_decimal_v = into_decimal<Digits...>::value;
}

#endif