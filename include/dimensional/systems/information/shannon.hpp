#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_SHANNON_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_SHANNON_HPP
#include <dimensional/units.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::information {
struct log2_info {
    using is_base_dimension = void;
    using is_dimesionless = void;
};

using shannon_t = make_unit_t<log2_info>;
inline constexpr shannon_t shannon{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::log2_info> {
    static constexpr char str[] = "Sh";
};
}

#endif