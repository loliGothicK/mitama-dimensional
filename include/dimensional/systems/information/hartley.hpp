#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_HARTLEY_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_HARTLEY_HPP
#include <dimensional/units.hpp>
#include <dimensional/io.hpp>
#include <dimensional/systems/information/nat.hpp>
#include <dimensional/systems/information/shannon.hpp>

namespace mitama::systems::information {
struct log10_info {
    using is_base_dimension = void;
    using is_dimesionless = void;
};

using hartley_t = make_unit_t<log10_info>;
}

namespace mitama {
template<>
struct abbreviation<mitama::systems::information::hartley_t> {
    static constexpr char str[] = "Hart";
};

template <class From, class To>
struct converter<quantity_t<systems::information::hartley_t, From>,
                 quantity_t<systems::information::shannon_t, To>>
{
    static constexpr To convert(quantity_t<systems::information::hartley_t, From> const& c)
        { return static_cast<To>(c.value() / std::log10(std::exp(2)) ); }
};

template <class From, class To>
struct converter<quantity_t<systems::information::hartley_t, From>,
                 quantity_t<systems::information::nat_t, To>>
{
    static constexpr To convert(quantity_t<systems::information::hartley_t, From> const& c)
        { return static_cast<To>(c.value() / std::log10(std::exp(1)) ); }
};

}

#endif