#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
#include <mitama/dimensional/systems/si/all.hpp>
#include <mitama/dimensional/quantity.hpp>
#include <mitama/dimensional/io.hpp>



namespace mitama::systems::si {
template<class> struct magnetization_synonym{};
using magnetization_t = make_synonym_t<magnetization_synonym, decltype(ampere<> / meter<>)>;

inline constexpr magnetization_t magnetization{};

}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FIELD_STRENGTH_HPP
namespace mitama {
template <> struct  abbreviation_<systems::si::magnetization_t> { static constexpr char str[] = "A/m"; };
}
#endif

#endif
