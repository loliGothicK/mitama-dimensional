#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
#include "../si_units/all.hpp"
#include "../quantity.hpp"
#include "../io.hpp"


namespace mitama::si {
using magnetization_t = decltype(ampere<> / meter<>);

inline constexpr magnetization_t magnetization{};
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FIELD_STRENGTH_HPP
namespace mitama {
template <> struct abbreviation<si::magnetization_t> { static constexpr char str[] = "A/m"; };
}
#endif

#endif
