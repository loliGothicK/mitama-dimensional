#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_BIT_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_BIT_HPP
#include <mitama/dimensional/systems/information/base_dimension/information.hpp>
#include <mitama/dimensional/units.hpp>
#include <mitama/dimensional/io.hpp>

namespace mitama::systems::information {
using bit_base_unit = base_units<info, 0>;
using bit_t = typename bit_base_unit::unit_type;

inline constexpr bit_t bit{};
inline constexpr bit_t bits{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::info, 0> {
    static constexpr char str[] = "b";
};
}

#endif
