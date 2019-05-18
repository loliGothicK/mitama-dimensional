#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFOMATION_PREFIX_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFOMATION_PREFIX_HPP
#include <ratio>
#include <dimensional/io.hpp>

namespace mitama::systems::information {
template <
    template<class> class Synonym,
    class Rational, class Unit,
    std::enable_if_t<mitamagic::is_rational_v<Rational> && is_units_v<Unit>,
                     bool> = false>
constexpr auto operator*(Rational, Synonym<dimensional_t<Unit>>) {
  return scaled_unit_t<Synonym<dimensional_t<Unit>>, Rational>{};
}
}

namespace mitama::systems::information {
inline constexpr auto kibi = std::ratio<(1ll << 10)>{};
inline constexpr auto mebi = std::ratio<(1ll << 20)>{};
inline constexpr auto gibi = std::ratio<(1ll << 30)>{};
inline constexpr auto tebi = std::ratio<(1ll << 40)>{};
inline constexpr auto pebi = std::ratio<(1ll << 50)>{};
}

namespace mitama {
template <> struct prefix_<std::decay_t<decltype(systems::information::kibi)>> { static constexpr char str[] = "Ki"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::mebi)>> { static constexpr char str[] = "Mi"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::gibi)>> { static constexpr char str[] = "Gi"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::tebi)>> { static constexpr char str[] = "Ti"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::pebi)>> { static constexpr char str[] = "Pi"; };
}
#endif