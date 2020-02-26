#ifndef MITAMA_DIMENSIONAL_SYSTEMS_SI_BASE_UNITS_LITERALS_CANDELA_LITERALS_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_SI_BASE_UNITS_LITERALS_CANDELA_LITERALS_HPP
#include <mitama/dimensional/systems/si/quantity.hpp>

namespace mitama::literals {
inline namespace units_literals {
inline namespace si_literals {
inline namespace luminous_intesity_literals {
    inline constexpr auto
    operator"" _cd(long double value)
    -> mitama::systems::si::quantity_t<mitama::systems::si::candela_t, long double>
    { return {value}; }

    inline constexpr auto
    operator"" _mcd(long double value)
    -> mitama::systems::si::quantity_t<mitama::systems::si::millicandela_t, long double>
    { return {value}; }

}}}}
#endif
