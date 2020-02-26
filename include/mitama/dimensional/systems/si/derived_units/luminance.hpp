#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINANCE_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct luminance_synonym{};
using luminance_t = make_synonym_t<luminance_synonym, decltype(candela<> * meter<-2>)>;

inline constexpr luminance_t luminance{};

}

namespace mitama {
template <> struct  abbreviation_<systems::si::luminance_t> { static constexpr char str[] = "cd/m^2"; };
}
#endif
