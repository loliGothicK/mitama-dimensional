#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_POP_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_POP_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct pop_synonym{};
using pop_t = make_synonym_t<pop_synonym, decltype(meters * second<-6>)>;

inline constexpr pop_t pop{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::pop_t> { static constexpr char str[] = "m/s^6"; };
}

#endif
