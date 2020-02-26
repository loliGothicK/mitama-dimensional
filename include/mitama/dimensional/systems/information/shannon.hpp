#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_SHANNON_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_SHANNON_HPP
#include <mitama/dimensional/systems/information/base_dimension/information.hpp>
#include <mitama/dimensional/units.hpp>
#include <mitama/dimensional/io.hpp>

namespace mitama::systems::information {
using shannon_base_unit = base_units<info, 4>;
using shannon_t = typename shannon_base_unit::unit_type;
inline constexpr shannon_t shannon{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::info, 4> {
    static constexpr char str[] = "Sh";
};
}

#endif
