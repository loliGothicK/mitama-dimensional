#ifndef MITAMA_DIMENSIONAL_IO_HPP
#define MITAMA_DIMENSIONAL_IO_HPP
#include "quantity.hpp"
#include "si_units/all.hpp"
#include "mitamagic/utility.hpp"
#include <iostream>
#include <type_traits>
#include <string>
#include <sstream>

namespace mitama {
template <class...> inline constexpr bool abbreviation_error_v = false;

template <class, class = void> struct abbreviation;
template <class, class = void> struct symbol_;
template <class, class = void> struct prefix_;

template <> struct symbol_<::mitama::si::length> {
  static constexpr char str[] = "m";
};
template <> struct symbol_<::mitama::si::electric_current> {
  static constexpr char str[] = "A";
};
template <> struct symbol_<::mitama::si::luminous_intensity> {
  static constexpr char str[] = "cd";
};
template <> struct symbol_<::mitama::si::thermodynamic_temperature> {
  static constexpr char str[] = "K";
};
template <> struct symbol_<::mitama::si::mass> {
  static constexpr char str[] = "g";
};
template <> struct symbol_<::mitama::si::amount_of_substance> {
  static constexpr char str[] = "mol";
};
template <> struct symbol_<::mitama::si::time> {
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
    using scale = std::conditional_t<std::is_same_v<D, ::mitama::si::mass>,
                                     std::ratio_multiply<S, std::kilo>, S>;
    return std::string(prefix_<scale>::str) + std::string(symbol_<D>::str) +
           (E::den == 1
                ? E::num == 1 ? std::string() : "^"s + std::to_string(E::num)
                : "^"s + std::to_string(E::num) + "/" + std::to_string(E::den));
  }
};

template <template <class> class Repr, class T, class Head, class... Tail>
std::string
to_string(quantity_t<Repr<dimensional_t<Head, Tail...>>, T> const &quantity) {
  using namespace std::literals;
  std::ostringstream ss;
  ss << quantity.get();
  return ss.str() + " [" + si_formatter<Head>::format() +
         (("·"s + si_formatter<Tail>::format()) + ... + "]");
}

template <template <class> class Repr, class T>
std::string
to_string(quantity_t<Repr<dimensional_t<>>, T> const &quantity) {
  std::ostringstream ss;
  ss << quantity.get();
  return ss.str() + " [dimensionless]";
}

template <template <class> class Repr, class T, class... Units>
std::ostream &
operator<<(std::ostream &os,
           quantity_t<Repr<dimensional_t<Units...>>, T> const &quantity) {
  if constexpr (is_complete_type<
                           abbreviation<Repr<dimensional_t<Units...>>>>::value) {
    return os << quantity.get() << " ["
              << abbreviation<Repr<dimensional_t<Units...>>>::str << "]";
  } else if constexpr (std::conjunction_v<
                    is_complete_type<prefix_<typename Units::scale>>...>) {
    return os << ::mitama::to_string(quantity);
  } else {
    static_assert(abbreviation_error_v<Repr<dimensional_t<Units...>>>,
                  "error: abbreviation is not available");
  }
}

} // namespace mitama
#endif