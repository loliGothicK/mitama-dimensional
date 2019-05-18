#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_BYTE_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_BYTE_HPP
#include <dimensional/systems/information/bit.hpp>

namespace mitama::systems::information {
struct info8 {
    using is_base_dimension = void;
    using is_dimesionless = void;
};

using byte_t = make_unit_t<info8>;

inline constexpr byte_t byte{};
inline constexpr byte_t bytes{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::info8> {
    static constexpr char str[] = "B";
};
}

#endif