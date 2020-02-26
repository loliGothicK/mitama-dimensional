#ifndef MITAMA_DIMENSIONAL_MITAMAGIC_UTILITY_EXT_HPP
#define MITAMA_DIMENSIONAL_MITAMAGIC_UTILITY_EXT_HPP
#include <type_traits>
#include <cstdint>
#include <utility>

namespace mitama {
template < class T > std::decay_t<T> inline constexpr decay_copy(T&& t)
  { return std::forward<T>(t); }
}

#endif