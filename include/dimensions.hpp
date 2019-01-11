#pragma once
#include <ratio>

namespace mitama {
// Dimension Types
struct Length {};

struct Mass {};

struct Time {};

template < class Dim, class Exponent > struct dimension_tag{};

template < class Dim, class Exponent = std::ratio<1>, class Scale = std::ratio<1> >
struct units_t: private dimension_tag<Dim, Exponent> {
    using dimension_type    = Dim;
    using exponent          = Exponent;
    using scale             = Scale;
    using tag               = dimension_tag<Dim, Exponent>;
};

}