#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FORCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_FORCE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>


namespace mitama::systems::si {
template<class> struct force_synonym{};
using force_t = make_synonym_t<force_synonym, decltype(kilogram<> * meter<> * second<-2>)>;
#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WEIGHT_HPP
inline constexpr force_t newton{};

#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WEIGHT_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::force_t> { static constexpr char str[] = "N"; };
}
#endif

#endif