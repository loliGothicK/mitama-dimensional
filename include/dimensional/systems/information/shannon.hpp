#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_SHANNON_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_SHANNON_HPP
#include <dimensional/units.hpp>
#include <dimensional/io.hpp>
#include <dimensional/systems/information/hartley.hpp>
#include <dimensional/systems/information/nat.hpp>
#include <cmath>

namespace mitama::systems::information {
struct log2_info {
    using is_base_dimension = void;
    using is_dimesionless = void;
};

using shannon_t = make_unit_t<log2_info>;
}

namespace mitama {
struct abbreviation<mitama::systems::information::shannon_t> {
    static constexpr char str[] = "Sh";
};
template <class From, class To>
struct converter<quantity_t<systems::information::shannon_t, From>,
                 quantity_t<systems::information::nat_t, To>>
{
    static constexpr To convert(quantity_t<systems::information::shannon_t, From> const& c)
        { return static_cast<To>(c.value() / std::log2(std::exp(1)) ); }
};

template <class From, class To>
struct converter<quantity_t<systems::information::shannon_t, From>,
                 quantity_t<systems::information::hartley_t, To>>
{
    static constexpr To convert(quantity_t<systems::information::shannon_t, From> const& c)
        { return static_cast<To>(c.value() / std::log2(10) ); }
};
}

#endif