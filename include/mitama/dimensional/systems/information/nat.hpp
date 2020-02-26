#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_NAT_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_NAT_HPP
#include <mitama/dimensional/systems/information/base_dimension/information.hpp>
#include <mitama/dimensional/units.hpp>
#include <mitama/dimensional/io.hpp>

namespace mitama::systems::information {
using nat_base_unit = base_units<info, 3>;
using nat_t = typename nat_base_unit::unit_type;
inline constexpr nat_t nat{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::info, 3> {
    static constexpr char str[] = "nat";
};

}

#endif
