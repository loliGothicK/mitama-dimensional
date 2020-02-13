#ifndef MITAMA_DIMENSIONAL_SYSTEMS_SI_BASE_UNITS_LITERALS_AMPERE_LITERALS_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_SI_BASE_UNITS_LITERALS_AMPERE_LITERALS_HPP
#include <dimensional/systems/si/quantity.hpp>

namespace mitama::literals {
inline namespace units_literals {
inline namespace si_literals {
inline namespace electric_current_literals {
    inline constexpr auto
    operator"" _A(long double value)
    -> mitama::systems::si::quantity_t<mitama::systems::si::ampere_t, long double>
    { return {value}; }

    inline constexpr auto
    operator"" _mA(long double value)
    -> mitama::systems::si::quantity_t<mitama::systems::si::milliampere_t, long double>
    { return {value}; }

    inline constexpr auto
    operator"" _\u03BCA(long double value)
    -> mitama::systems::si::quantity_t<mitama::systems::si::microampere_t, long double>
    { return {value}; }

    inline constexpr auto
    operator"" _nA(long double value)
    -> mitama::systems::si::quantity_t<mitama::systems::si::nanoampere_t, long double>
    { return {value}; }

    inline constexpr auto
    operator"" _kA(long double value)
    -> mitama::systems::si::quantity_t<mitama::systems::si::kiloampere_t, long double>
    { return {value}; }

    operator"" _MA(long double value)
    -> mitama::systems::si::quantity_t<mitama::systems::si::megaampere_t, long double>
    { return {value}; }

}}}}
#endif
