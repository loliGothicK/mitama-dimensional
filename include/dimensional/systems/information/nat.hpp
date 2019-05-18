#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_NAT_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_NAT_HPP
#include <dimensional/units.hpp>
#include <dimensional/io.hpp>
#include <dimensional/systems/information/hartley.hpp>
#include <dimensional/systems/information/shannon.hpp>

namespace mitama::systems::information {
struct ln_info {
    using is_base_dimension = void;
    using is_dimesionless = void;
};

using nat_t = make_unit_t<ln_info>;
}

namespace mitama {
template<>
struct abbreviation<mitama::systems::information::nat_t> {
    static constexpr char str[] = "nat";
};

template <class From, class To>
struct converter<quantity_t<systems::information::nat_t, From>,
                 quantity_t<systems::information::shannon_t, To>>
{
    static constexpr To convert(quantity_t<systems::information::nat_t, From> const& c)
        { return static_cast<To>(c.value() / std::log(std::exp(2)) ); }
};

template <class From, class To>
struct converter<quantity_t<systems::information::nat_t, From>,
                 quantity_t<systems::information::hartley_t, To>>
{
    static constexpr To convert(quantity_t<systems::information::nat_t, From> const& c)
        { return static_cast<To>(c.value() / std::log(10) ); }
};
}

#endif