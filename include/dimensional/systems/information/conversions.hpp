#ifndef MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_CONVERSIONS_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_INFORMATION_CONVERSIONS_HPP
#include <dimensional/io.hpp>
#include <dimensional/systems/information/shannon.hpp>
#include <dimensional/systems/information/nat.hpp>
#include <dimensional/systems/information/hartley.hpp>
#include <dimensional/systems/information/bit.hpp>
#include <dimensional/systems/information/byte.hpp>
#include <cmath>

namespace mitama {

template <class From, class To>
struct converter<quantity_t<::mitama::systems::information::nat_t, From>,
                 quantity_t<::mitama::systems::information::shannon_t, To>>
{
    static constexpr To convert(quantity_t<::mitama::systems::information::nat_t, From> const& c)
        { return static_cast<To>(c.value() / std::log(std::exp(2)) ); }
};

template <class From, class To>
struct converter<quantity_t<::mitama::systems::information::nat_t, From>,
                 quantity_t<::mitama::systems::information::hartley_t, To>>
{
    static constexpr To convert(quantity_t<::mitama::systems::information::nat_t, From> const& c)
        { return static_cast<To>(c.value() / std::log(10) ); }
};

template <class From, class To>
struct converter<quantity_t<::mitama::systems::information::hartley_t, From>,
                 quantity_t<::mitama::systems::information::shannon_t, To>>
{
    static constexpr To convert(quantity_t<::mitama::systems::information::hartley_t, From> const& c)
        { return static_cast<To>(c.value() / std::log10(std::exp(2)) ); }
};

template <class From, class To>
struct converter<quantity_t<::mitama::systems::information::hartley_t, From>,
                 quantity_t<::mitama::systems::information::nat_t, To>>
{
    static constexpr To convert(quantity_t<::mitama::systems::information::hartley_t, From> const& c)
        { return static_cast<To>(c.value() / std::log10(std::exp(1)) ); }
};

template <class From, class To>
struct converter<quantity_t<::mitama::systems::information::shannon_t, From>,
                 quantity_t<::mitama::systems::information::nat_t, To>>
{
    static constexpr To convert(quantity_t<::mitama::systems::information::shannon_t, From> const& c)
        { return static_cast<To>(c.value() / std::log2(std::exp(1)) ); }
};

template <class From, class To>
struct converter<quantity_t<::mitama::systems::information::shannon_t, From>,
                 quantity_t<::mitama::systems::information::hartley_t, To>>
{
    static constexpr To convert(quantity_t<::mitama::systems::information::shannon_t, From> const& c)
        { return static_cast<To>(c.value() / std::log2(10) ); }
};

template <class From, class To>
struct converter<quantity_t<::mitama::systems::information::bit_t, From>,
                 quantity_t<::mitama::systems::information::byte_t, To>>
{
    static constexpr To convert(quantity_t<::mitama::systems::information::byte_t, From> const& c)
        { return static_cast<To>(c.value() / 8 ); }
};

template <class From, class To>
struct converter<quantity_t<::mitama::systems::information::byte_t, From>,
                 quantity_t<::mitama::systems::information::bit_t, To>>
{
    static constexpr To convert(quantity_t<::mitama::systems::information::bit_t, From> const& c)
        { return static_cast<To>(c.value() * 8 ); }
};

}

#endif