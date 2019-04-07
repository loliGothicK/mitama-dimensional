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

