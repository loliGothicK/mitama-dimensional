#ifndef MITAMA_DIMENSIONAL_IO_HPP
#define MITAMA_DIMENSIONAL_IO_HPP
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/mitamagic/utility_ext.hpp>
#include <iostream>
#include <type_traits>
#include <string>
#include <sstream>

namespace mitama {
template <class, class = void> struct abbreviation_;

template <template <class> class, class> struct make_synonym{};

template <template <class> class Synonym, template<class> class Synonym_, class... Units>
struct make_synonym<Synonym, Synonym_<dimensional_t<Units...>>>{
  using type = Synonym<dimensional_t<Units...>>;
};

template <template <class> class Synonym, class... Units>
struct make_synonym<Synonym, dimensional_t<Units...>>{
  using type = Synonym<dimensional_t<Units...>>;
};

template <template<class> class Synonym, class Dim>
using make_synonym_t = typename make_synonym<Synonym, std::decay_t<Dim>>::type;

template <class, int , class = void> struct symbol_;
template <class, class = void> struct prefix_;

template <> struct symbol_<::mitama::systems::si::length, 0> {
  static constexpr char str[] = "m";
};
template <> struct symbol_<::mitama::systems::si::electric_current, 0> {
  static constexpr char str[] = "A";
};
template <> struct symbol_<::mitama::systems::si::luminous_intensity, 0> {
  static constexpr char str[] = "cd";
};
template <> struct symbol_<::mitama::systems::si::thermodynamic_temperature, 0> {
  static constexpr char str[] = "K";
};
template <> struct symbol_<::mitama::systems::si::mass, 0> {
  static constexpr char str[] = "g";
};
template <> struct symbol_<::mitama::systems::si::amount_of_substance, 0> {
  static constexpr char str[] = "mol";
};
template <> struct symbol_<::mitama::systems::si::time, 0> {
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

template <int I, class D, class E, class S, class Sys>
struct si_formatter<
    units_t<I, D, E, S, Sys>,
    std::enable_if_t<std::conjunction_v<is_complete_type<prefix_<S>>,
                                        is_complete_type<symbol_<D, I>>>>> {
  static std::string format() {
    using namespace std::literals;
    using scale = std::conditional_t<std::is_same_v<D, ::mitama::systems::si::mass>,
                                     std::ratio_multiply<S, std::kilo>, S>;
    return std::string(prefix_<scale>::str) + std::string(symbol_<D, I>::str) +
           (E::den == 1
                ? E::num == 1 ? std::string() : "^"s + std::to_string(E::num)
                : "^"s + std::to_string(E::num) + "/" + std::to_string(E::den));
  }
};

namespace _detail {
template <template <class> class Synonym, class T, class Head, class... Tail, class S>
std::string
abbreviation(quantity_t<Synonym<dimensional_t<Head, Tail...>>, T, S> const &quantity) {
  using namespace std::literals;
  return "[" + si_formatter<Head>::format() +
         ((" "s + si_formatter<Tail>::format()) + ... + "]");
}

template <template <class> class Synonym, class T, class S>
std::string
abbreviation(quantity_t<Synonym<dimensional_t<>>, T, S> const &quantity) {
  return "[dimensionless]";
}
}

template <template <class> class Synonym, class T, class... Units, class S>
std::string
abbreviation(quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using namespace std::literals::string_literals;
  if constexpr (is_complete_type<
                            abbreviation_<Synonym<dimensional_t<Units...>>>>::value) {
    return "["s +  abbreviation_<Synonym<dimensional_t<Units...>>>::str << "]";
  } else if constexpr (std::conjunction_v<
                    is_complete_type<prefix_<typename Units::scale>>...>) {
    return "["s + mitama::_detail::abbreviation(quantity) + "]";
  } else {
    static_assert([]{ return false; }(), "error: abbreviation is not available");
  }
}

template <template <class> class Synonym, class T, class... Units, class S>
std::ostream &
operator<<(std::ostream &os,
           quantity_t<Synonym<dimensional_t<Units...>>, T, S> const &quantity) {
  using namespace std::literals::string_literals;
  if constexpr (is_complete_type<abbreviation_<Synonym<dimensional_t<Units...>>>>::value) {
    return os << quantity.value() << " [" <<  abbreviation_<Synonym<dimensional_t<Units...>>>::str << "]";
  } else if constexpr (std::conjunction_v<is_complete_type<prefix_<typename Units::scale>>...>) {
    return os << quantity.value() << " " << mitama::_detail::abbreviation(quantity);
  } else {
    static_assert([]{ return false; }(), "error: abbreviation is not available");
  }
}

} // namespace mitama

#endif
