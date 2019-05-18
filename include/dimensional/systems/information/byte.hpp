#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_BYTE_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_BYTE_HPP
#include <dimensional/systems/information/bit.hpp>

namespace mitama::systems::information {
using byte_t = scaled_unit_t<bit_t, std::ratio<8>>;
}

namespace mitama {
template<>
struct abbreviation<mitama::systems::information::byte_t> {
    static constexpr char str[] = "bit";
};
}

#endif