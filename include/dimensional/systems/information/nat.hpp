#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_NAT_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_NAT_HPP
#include <dimensional/units.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::information {
struct ln_info {
    using is_base_dimension = void;
    using is_dimesionless = void;
};

using nat_t = make_unit_t<ln_info>;
inline constexpr nat_t nat{};
}

namespace mitama {
template<>
struct symbol_<mitama::systems::information::ln_info> {
    static constexpr char str[] = "nat";
};

}

#endif