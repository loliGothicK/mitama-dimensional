#pragma once
#include "../dimensions.hpp"

namespace mitama{
template < class... >
struct dimensional_t;

using meters = dimensional_t<units_t<Length>>;
using millimeters = dimensional_t<units_t<Length, std::ratio<1>, std::milli>>;

}