#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POP_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POP_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct pop_repr{};
using pop_t = make_synonym_t<pop_repr, decltype(meters * second<-6>)>;

inline constexpr pop_t pop{};
}

namespace mitama {
template <> struct abbreviation<si::pop_t> { static constexpr char str[] = "m/s^6"; };
}

#endif
