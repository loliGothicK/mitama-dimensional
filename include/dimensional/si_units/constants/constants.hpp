#include "../all.hpp"
#include "../../quantity.hpp"
#include "../../derived_units/action.hpp"
#include "../../derived_units/electric_charge.hpp"
#include "../../derived_units/heat_capacity.hpp"
#include "../../derived_units/frequency.hpp"
#include "../../derived_units/velocity.hpp"
#include "../../derived_units/luminous_efficacy.hpp"

namespace mitama::si::constants{

    inline constexpr quantity<action_t, long double> h = static_cast<long double>(6.62607015e-34l);

    inline constexpr quantity<electric_charge_t, long double> e = static_cast<long double>(1.602176634e-19l);

    inline constexpr quantity<heat_capacity_t, long double> k  = static_cast<long double>(1.380649e-23l);

    inline constexpr quantity<reciprocal_t<micromol_t>,long long> NA = static_cast<long long>(602214076000000000ll);

    inline constexpr quantity<frequency_t,long long> delta_nu_133Cs = static_cast<long long>(9192631770ll);

    inline constexpr quantity<velocity_t,long long> c = static_cast<long long>(299792458ll);

    inline constexpr quantity<luminous_efficacy_t,long long> Kcd = static_cast<long long>(683);
} 