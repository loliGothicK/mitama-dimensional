#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFOMATION_PREFIX_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFOMATION_PREFIX_HPP
#include <ratio>
#include <dimensional/io.hpp>

namespace mitama::systems::information {
inline constexpr auto kibi = std::ratio<1'024>{};
inline constexpr auto mebi = std::ratio<1'048'576>{};
inline constexpr auto gibi = std::ratio<1'073'741'824>{};
inline constexpr auto tebi = std::ratio<1'099'511'627'776>{};
inline constexpr auto pebi = std::ratio<1'125'899'906'842'624>{};
inline constexpr auto exbi = std::ratio<1'152'921'504'606'846'976>{};
}
namespace mitama {
template <> struct prefix_<std::decay_t<decltype(systems::information::kibi)>> { static constexpr char str[] = "Ki"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::mebi)>> { static constexpr char str[] = "Mi"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::gibi)>> { static constexpr char str[] = "Gi"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::tebi)>> { static constexpr char str[] = "Ti"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::pebi)>> { static constexpr char str[] = "Pi"; };
template <> struct prefix_<std::decay_t<decltype(systems::information::exbi)>> { static constexpr char str[] = "Ei"; };
}
#endif