#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ACTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::si {
struct radioactivity { using is_base_dimension = void; };
using radioactivity_t = make_unit_t<radioactivity>;
inline constexpr radioactivity_t becquerel{};
}

namespace mitama {
template <> struct symbol_<si::radioactivity> { static constexpr char str[] = "Bq"; };
}
#endif