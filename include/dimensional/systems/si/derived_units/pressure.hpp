#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_PASCAL_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_PASCAL_HPP
#ifdef pascal
  #undef pascal // Fucking MSVC
#endif
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>


namespace mitama::systems::si {
template<class> struct pressure_synonym{};
using pressure_t = make_synonym_t<pressure_synonym, decltype(kilogram<> * meter<-1> * second<-2>)>;
inline constexpr pressure_t pascal{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::pressure_t> { static constexpr char str[] = "Pa"; };
}
#endif
