#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WEIGHT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_WEIGHT_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"

namespace mitama::si {
template<class> struct weight_repr{};
using weight_t = make_synonym_t<weight_repr, decltype(kilogram<> * meter<> * second<-2>)>;
#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FORCE_HPP
inline constexpr weight_t newton{};
#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FORCE_HPP
namespace mitama {
template <> struct abbreviation<si::weight_t> { static constexpr char str[] = "N"; };
}
#endif

#endif