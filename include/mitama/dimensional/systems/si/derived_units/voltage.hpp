#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLTAGE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_VOLTAGE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct voltage_synonym{};
using voltage_t = make_synonym_t<voltage_synonym, decltype(kilogram<> * meter<2> * second<-3> * ampere<-1>)>;

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_POTENTIAL_HPP
inline constexpr voltage_t volts{};

template < std::intmax_t N >
inline constexpr powered_t<voltage_t, N> volt{};
#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_POTENTIAL_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::voltage_t> { static constexpr char str[] = "V"; };
}
#endif

#endif