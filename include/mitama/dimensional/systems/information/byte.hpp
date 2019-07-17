#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_BYTE_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_BYTE_HPP
#include <mitama/dimensional/systems/information/base_dimension/information.hpp>
#include <mitama/dimensional/systems/information/bit.hpp>

namespace mitama::systems::information {
using byte_base_unit = base_units<info, 1>;
using byte_t = typename byte_base_unit::unit_type;

inline constexpr byte_t byte{};
inline constexpr byte_t bytes{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::info, 1> {
    static constexpr char str[] = "B";
};
}

#endif
