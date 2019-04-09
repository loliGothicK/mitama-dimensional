#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLTAGE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLTAGE_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
template<class> struct voltage_repr{};
using voltage_t = make_synonym_t<voltage_repr, decltype(kilogram<> * meter<2> * second<-3> * ampere<-1>)>;

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_POTENTIAL_HPP
inline constexpr voltage_t volts{};
template < std::intmax_t N >
inline constexpr powered_t<voltage_t, N> volt{};
#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_POTENTIAL_HPP
namespace mitama {
template <> struct abbreviation<si::voltage_t> { static constexpr char str[] = "V"; };
}
#endif

#endif