#pragma once
#include <boost/format.hpp>
#include <catch2/catch.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/io.hpp>
#include <dimensional/prefix.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::si;
using namespace mitama::nonsi;

inline auto fmt = [](auto const &a) {
  return (boost::format("%1%") % a).str();
};
using namespace std::literals;

template <class Prefix, class Unit, class = void> struct test_c {
  inline static constexpr auto value = 1 | Prefix{} * Unit{};
  static std::string expexted() {
    return std::to_string(1) + " [" + std::string(prefix_<Prefix>::str) +
           std::string(symbol_<typename basis_<Unit>::template type<0>>::str) +
           "]";
  }
};
template <class Prefix, class Unit>
struct test_c<Prefix, Unit,
              std::enable_if_t<std::is_same_v<
                  typename basis_<Unit>::template type<0>, mass>>> {
  inline static constexpr auto value = 1 | Prefix{} * Unit{};
  static std::string expexted() {
    return std::to_string(1) + " [" +
           std::string(prefix_<std::ratio_multiply<Prefix, std::kilo>>::str) +
           std::string(symbol_<typename basis_<Unit>::template type<0>>::str) +
           "]";
  }
};
