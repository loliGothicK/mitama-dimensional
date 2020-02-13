#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CONDUCTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CONDUCTANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct conductance_synonym{};
using conductance_t = make_synonym_t<conductance_synonym, decltype(kilogram<-1> * meter<-2> * second<3> * ampere<2>)>;

inline constexpr conductance_t siemens{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::conductance_t> { static constexpr char str[] = "S"; };
}
#endif
