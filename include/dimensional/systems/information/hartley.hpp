#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_HARTLEY_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_HARTLEY_HPP
#include <dimensional/systems/information/base_dimension/information.hpp>
#include <dimensional/units.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::information {
using hartley_base_unit = base_units<info, 2>;
using hartley_t = typename hartley_base_unit::unit_type;
inline constexpr hartley_t hartley{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::info, 2> {
    static constexpr char str[] = "Hart";
};

}

#endif
