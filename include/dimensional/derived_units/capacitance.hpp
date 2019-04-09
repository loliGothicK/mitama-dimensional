#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CAPACITANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CAPACITANCE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct capacitance_repr{};
using capacitance_t = make_synonym_t<capacitance_repr, decltype(kilogram<-1> * meter<-2> * second<4> * ampere<2>)>;

inline constexpr capacitance_t farad{}; 
}

namespace mitama {
template <> struct abbreviation<si::capacitance_t> { static constexpr char str[] = "F"; };
}
#endif
