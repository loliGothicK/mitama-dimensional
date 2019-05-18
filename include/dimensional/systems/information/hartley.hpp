#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_HARTLEY_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_HARTLEY_HPP
#include <dimensional/units.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::information {
struct log10_info {
    using is_base_dimension = void;
    using is_dimesionless = void;
};

using hartley_t = make_unit_t<log10_info>;
inline constexpr hartley_t hartley{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::log10_info> {
    static constexpr char str[] = "Hart";
};

}

#endif