#ifndef MITAMA_DIMENSIONAL_FWD_UNITS_FWD_HPP
#define MITAMA_DIMENSIONAL_FWD_UNITS_FWD_HPP
#include <ratio>
#include <mitama/dimensional/fwd/system.hpp>

namespace mitama {
    template <int N, class Dim, class = std::ratio<1>, class = std::ratio<1>, class = system<>>
    struct units_t;
}
#endif
