#ifndef MITAMA_DIMENSIONAL_CURRENCY_HPP
#define MITAMA_DIMENSIONAL_CURRENCY_HPP
#include <dimensional/units.hpp>
#include <dimensional/io.hpp>

namespace mitama {
// currency base dimension tag
struct currency { using is_base_dimension = void; };

using jpy_t = make_unit_t<currency>;

inline constexpr jpy_t yen{};

template <> struct symbol_<currency> {
    inline static constexpr char str[] = "JPY";
};

}
#endif