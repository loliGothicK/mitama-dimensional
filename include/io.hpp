#ifndef MITAMA_DIMENSIONAL_IO_HPP
#define MITAMA_DIMENSIONAL_IO_HPP
#include "quantity.hpp"
#include "si/all.hpp"
#include <iostream>
#include <type_traits>

namespace mitama {
template <class...> inline constexpr bool abbreviation_error_v = false;
template <class T, class = void> struct is_complete_type : std::false_type {};

template <class T>
struct is_complete_type<T, std::void_t<decltype(sizeof(T))>> : std::true_type {
};

template <class, class = void> struct abbreviation;
template <class, class = void> struct symbol_;
template <class, class = void> struct prefix_;

template <> struct symbol_<::mitama::length> {
  static constexpr char str[] = "m";
};
template <> struct symbol_<::mitama::electric_current> {
  static constexpr char str[] = "A";
};
template <> struct symbol_<::mitama::luminous_intensity> {
  static constexpr char str[] = "cd";
};
template <> struct symbol_<::mitama::thermodynamic_temperature> {
  static constexpr char str[] = "K";
};
template <> struct symbol_<::mitama::mass> {
  static constexpr char str[] = "g";
};
template <> struct symbol_<::mitama::amount_of_substance> {
  static constexpr char str[] = "mol";
};
template <> struct symbol_<::mitama::time> {
  static constexpr char str[] = "s";
};
template <> struct prefix_<std::ratio<1>> { static constexpr char str[] = ""; };

template <> struct prefix_<std::tera> { static constexpr char str[] = "T"; };
template <> struct prefix_<std::giga> { static constexpr char str[] = "G"; };
template <> struct prefix_<std::mega> { static constexpr char str[] = "M"; };
template <> struct prefix_<std::kilo> { static constexpr char str[] = "k"; };
template <> struct prefix_<std::hecto> { static constexpr char str[] = "h"; };
template <> struct prefix_<std::deca> { static constexpr char str[] = "da"; };
template <> struct prefix_<std::deci> { static constexpr char str[] = "d"; };
template <> struct prefix_<std::centi> { static constexpr char str[] = "c"; };
template <> struct prefix_<std::milli> { static constexpr char str[] = "m"; };
template <> struct prefix_<std::micro> { static constexpr char str[] = "u"; };
template <> struct prefix_<std::nano> { static constexpr char str[] = "n"; };
template <> struct prefix_<std::pico> { static constexpr char str[] = "p"; };

template <class, class = void> struct si_formatter;

template <class D, class E, class S>
struct si_formatter<
    units_t<D, E, S>,
    std::enable_if_t<std::conjunction_v<is_complete_type<prefix_<S>>,
                                        is_complete_type<symbol_<D>>>>> {
  static std::string format() {
    using namespace std::literals;
    using scale = std::conditional_t<std::is_same_v<D, ::mitama::mass>,
                                     std::ratio_multiply<S, std::kilo>, S>;
    return std::string(prefix_<scale>::str) + std::string(symbol_<D>::str) +
           (E::den == 1
                ? E::num == 1 ? std::string() : "^"s + std::to_string(E::num)
                : "^"s + std::to_string(E::num) + "/" + std::to_string(E::den));
  }
};

template <class T, class _, class... Units>
std::string
to_string(quantity_t<dimensional_t<_, Units...>, T> const &quantity) {
  using std::to_string;
  using namespace std::literals;
  return to_string(quantity.get()) + "[" +
         (si_formatter<Units>::format() + ...) + "]";
}

template <class D>
struct abbreviation<D,
                    std::enable_if_t<mitamagic::is_dimensionless<D>::value>> {
  static constexpr char str[] = "dimensionless";
};

template <class E>
inline std::string exponent = [] {
  using namespace std::literals;
  if constexpr (std::ratio_equal_v<E, std::ratio<1>>)
    return "";
  else if constexpr (E::den == 1)
    return "^"s + std::to_string(E::num);
  else
    return "^"s + std::to_string(E::num) + "/" + std::to_string(E::den);
}();

template <class T, class _, class... Units>
//,std::enable_if_t<std::conjunction_v<is_complete_type<abbreviation<typename
// Units::basic_type>>...>, bool> = false >
std::ostream &
operator<<(std::ostream &os,
           quantity_t<dimensional_t<_, Units...>, T> const &quantity) {
  if constexpr (is_complete_type<
                           abbreviation<dimensional_t<_, Units...>>>::value) {
    return os << quantity.get() << "[ "
              << abbreviation<dimensional_t<_, Units...>>::str << " ]";
  } else if constexpr (std::conjunction_v<
                    is_complete_type<prefix_<typename Units::scale>>...>) {
    return os << ::mitama::to_string(quantity);
  } else {
    static_assert(abbreviation_error_v<dimensional_t<_, Units...>>,
                  "error: abbreviation is not available");
  }
}

} // namespace mitama
#endif