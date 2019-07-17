#pragma once
#include <boost/format.hpp>
#include <catch2/catch.hpp>
#include <mitama/dimensional/arithmetic.hpp>
#include <mitama/dimensional/io.hpp>
#include <mitama/dimensional/systems/si/prefix.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/systems/si/all.hpp>
#include <test_util.hpp>

using namespace mitama;
using namespace mitama::systems::si;
using namespace mitama::systems::nonsi;

inline auto fmt = [](auto const &a) {
  return (boost::format("%1%") % a).str();
};
using namespace std::literals;

