#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_ACTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_ACTIVITY_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using catalytic_activity_t = decltype(second<-1> * mol<>);

inline constexpr catalytic_activity_t katal{}; 
}

namespace mitama {
template <> struct abbreviation<si::catalytic_activity_t> { static constexpr char str[] = "kat"; };
}
#endif
