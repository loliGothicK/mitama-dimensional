#ifndef MITAMA_DIMENSIONAL_REFINEMENT_HPP
#define MITAMA_DIMENSIONAL_REFINEMENT_HPP
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/mitamagic/type_list.hpp>
#include <type_traits>

namespace mitama {

namespace sym {
class refinement_symbol_tag {};

template <std::intmax_t N = 1> struct L : private refinement_symbol_tag {
  using basis = ::mitama::systems::si::length;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct M : private refinement_symbol_tag {
  using basis = ::mitama::systems::si::mass;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct T : private refinement_symbol_tag {
  using basis = ::mitama::systems::si::time;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct I : private refinement_symbol_tag {
  using basis = ::mitama::systems::si::electric_current;
  using exp = std::ratio<N>;
};
template <std::intmax_t N = 1> struct S : private refinement_symbol_tag {
  using basis = ::mitama::systems::si::thermodynamic_temperature;
  using exp = std::ratio<N>;
};
template <std::intmax_t E = 1> struct N : private refinement_symbol_tag {
  using basis = ::mitama::systems::si::amount_of_substance;
  using exp = std::ratio<E>;
};
template <std::intmax_t N = 1> struct J : private refinement_symbol_tag {
  using basis = ::mitama::systems::si::luminous_intensity;
  using exp = std::ratio<N>;
};

template <class T>
using is_refinement_symbol = std::is_base_of<refinement_symbol_tag, T>;
template <class T>
inline constexpr bool is_refinement_symbol_v = is_refinement_symbol<T>::value;

} // namespace sym

template <class, template <class> class, class> struct refinement_type;
template <class, template <class> class, class...> struct refinement_type_for;

template <template <class> class Pred, class... Symbols>
struct refinement_type_for<
    std::enable_if_t<std::conjunction_v<sym::is_refinement_symbol<Symbols>...>>,
    Pred, Symbols...> {
  template <class Q,
            std::enable_if_t<
                Pred<is_same_dimensional<
                     std::decay_t<Q>,
                     quantity_t<make_dimensional_t<units_t<0,
                         typename Symbols::basis, typename Symbols::exp>...>>>>::value,
                bool> = false>
  constexpr decltype(auto) operator()(Q &&q) const {
    return std::forward<Q>(q);
  }

  decltype(auto) operator()(...) const = delete;

  template <class Q,
            std::enable_if_t<
                Pred<is_same_dimensional<
                     std::decay_t<Q>,
                     quantity_t<make_dimensional_t<units_t<0,
                         typename Symbols::basis, typename Symbols::exp>...>>>>::value,
                bool> = false>
  constexpr decltype(auto) operator|=(Q &&q) const {
    return std::forward<Q>(q);
  }

  template < class... Args >
  decltype(auto) operator|=(Args&&...) const = delete;
};

template <template <class> class Pred, template <class...> class Requires, class... Symbols>
struct refinement_type<
    std::enable_if_t<std::conjunction_v<sym::is_refinement_symbol<Symbols>...>>,
    Pred, Requires<Symbols...>> {
  template <class Q,
            std::enable_if_t<
                Pred<is_same_dimensional<
                     std::decay_t<Q>,
                     quantity_t<make_dimensional_t<units_t<0,
                         typename Symbols::basis, typename Symbols::exp>...>>>>::value,
                bool> = false>
  constexpr decltype(auto) operator()(Q &&q) const {
    return std::forward<Q>(q);
  }

  decltype(auto) operator()(...) const = delete;

  template <class Q,
            std::enable_if_t<
                Pred<is_same_dimensional<
                     std::decay_t<Q>,
                     quantity_t<make_dimensional_t<units_t<0,
                         typename Symbols::basis, typename Symbols::exp>...>>>>::value,
                bool> = false>
  constexpr decltype(auto) operator|=(Q &&q) const {
    return std::forward<Q>(q);
  }

  template <class... Dummy>
  decltype(auto) operator|=(Dummy&&...) const = delete;
};

template <class... Requires>
inline constexpr refinement_type_for<void, identity, Requires...> accepts_for{};

template <class Requires>
inline constexpr refinement_type<void, identity, Requires> accepts{};

template <class... Requires>
inline constexpr refinement_type_for<void, std::negation, Requires...> rejects_for{};

template <class Requires>
inline constexpr refinement_type<void, std::negation, Requires> rejects{};


template <class, template <class> class, class...> struct partial_refinement_type_for;
template <class, template <class> class, class> struct partial_refinement_type;

template <template <class> class Pred, class... Symbols>
struct partial_refinement_type_for<
	std::enable_if_t<std::conjunction_v<sym::is_refinement_symbol<Symbols>...>>,
	Pred, Symbols...> {

  template <class Q,
            std::enable_if_t<
              Pred<std::conjunction<
                std::is_base_of<
                  dimension_tag<0, typename Symbols::basis, typename Symbols::exp>,
                  typename std::decay_t<Q>::dimension_type
                >...
              >>::value,
            bool> = false>
  constexpr decltype(auto) operator()(Q &&q) const {
    return std::forward<Q>(q);
  }

  decltype(auto) operator()(...) const = delete;

  template <class Q,
            std::enable_if_t<
              Pred<std::conjunction<
                std::is_base_of<
                  dimension_tag<0, typename Symbols::basis, typename Symbols::exp>,
                  typename std::decay_t<Q>::dimension_type
                >...
              >>::value,
            bool> = false>
  constexpr decltype(auto) operator|=(Q &&q) const {
    return std::forward<Q>(q);
  }

  template <class... Dummy>
  decltype(auto) operator|=(Dummy&&...) const = delete;
};

template <template <class> class Pred, template <class...> class Requires, class... Symbols>
struct partial_refinement_type<
	std::enable_if_t<std::conjunction_v<sym::is_refinement_symbol<Symbols>...>>,
	Pred, Requires<Symbols...>> {

  template <class Q,
            std::enable_if_t<
              Pred<std::conjunction<
                std::is_base_of<
                  dimension_tag<0, typename Symbols::basis, typename Symbols::exp>,
                  typename std::decay_t<Q>::dimension_type
                >...
              >>::value,
            bool> = false>
  constexpr decltype(auto) operator()(Q &&q) const {
    return std::forward<Q>(q);
  }

  decltype(auto) operator()(...) const = delete;

  template <class Q,
            std::enable_if_t<
              Pred<std::conjunction<
                std::is_base_of<
                  dimension_tag<0, typename Symbols::basis, typename Symbols::exp>,
                  typename std::decay_t<Q>::dimension_type
                >...
              >>::value,
            bool> = false>
  constexpr decltype(auto) operator|=(Q &&q) const {
    return std::forward<Q>(q);
  }

  template <class... Dummy>
  decltype(auto) operator|=(Dummy&&...) const = delete;
};

template <class... Requires>
inline constexpr partial_refinement_type_for<void, identity, Requires...> partial_accepts_for{};

template <class Requires>
inline constexpr partial_refinement_type<void, identity, Requires> partial_accepts{};

template <class... Requires>
inline constexpr partial_refinement_type_for<void, std::negation, Requires...> partial_rejects_for{};

template <class Requires>
inline constexpr partial_refinement_type<void, std::negation, Requires> partial_rejects{};
} // namespace mitama

namespace mitama {
using length_r = mitamagic::type_list<sym::L<1>>;
using mass_r = mitamagic::type_list<sym::M<1>>;
using time_r = mitamagic::type_list<sym::T<1>>;
using current_r = mitamagic::type_list<sym::I<1>>;
using thermo_r = mitamagic::type_list<sym::S<1>>;
using amount_r = mitamagic::type_list<sym::N<1>>;
using luminous_r = mitamagic::type_list<sym::J<1>>;
} // namespace mitama

namespace mitama {
namespace mitamagic {

template < class Unit >
struct atomic_refinement_symbol
  : ::mitama::sym::refinement_symbol_tag
{
  using basis = typename Unit::dimension_type;
  using exp   = typename Unit::exponent;
};
} // ! namespace mitamagic


template < class > struct make_refinement_symbol;

template < template <class> class Synonym, class... Units >
struct make_refinement_symbol<Synonym<dimensional_t<Units...>>>
{
  using type = mitamagic::type_list<mitamagic::atomic_refinement_symbol<Units>...>;
};

template < class T >
using make_refinement_symbol_t = typename make_refinement_symbol<std::decay_t<T>>::type;

} // ! namespace mitama

#endif
