#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CRACKLE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CRACKLE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using crackle_t = decltype(meters * second<-5>);

inline constexpr crackle_t crackle{};
}

namespace mitama {
template <> struct abbreviation<si::crackle_t> { static constexpr char str[] = "m/s^5"; };
}

#endif
