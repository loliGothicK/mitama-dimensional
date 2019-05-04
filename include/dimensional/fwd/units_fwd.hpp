#ifndef MITAMA_DIMENSIONAL_FWD_UNITS_FWD_HPP
#define MITAMA_DIMENSIONAL_FWD_UNITS_FWD_HPP
#include <ratio>
namespace mitama {
    template <class Dim, class = std::ratio<1>, class = std::ratio<1>>
    struct units_t;
}
#endif
