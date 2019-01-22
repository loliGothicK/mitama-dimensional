#pragma once/
#include "../units.hpp"

namespace mitama {
// currency base dimension tag
struct currency {};

using jpy_t = make_unit_t<currency>;

inline constexpr jpy_t yen{}; 

}