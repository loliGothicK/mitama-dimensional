// main is provided in tests-main.cpp
#include "test_util.hpp"
#include <boost/format.hpp>
#include <catch2/catch.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/derived_units/named_units.hpp>
#include <dimensional/io.hpp>
#include <dimensional/prefix.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/si/all.hpp>

using namespace mitama;
inline auto fmt = [](auto const &a) {
  return (boost::format("%1%") % a).str();
};
using namespace std::literals;

template <class Prefix, class Unit, class = void> struct test_c {
  inline static constexpr auto value = 1 | Prefix{} * Unit{};
  static std::string expexted() {
    return std::to_string(1) + " [" + std::string(prefix_<Prefix>::str) +
           std::string(symbol_<typename basis_<Unit>::template type<0>>::str) +
           "]";
  }
};
template <class Prefix, class Unit>
struct test_c<Prefix, Unit,
              std::enable_if_t<std::is_same_v<
                  typename basis_<Unit>::template type<0>, mass>>> {
  inline static constexpr auto value = 1 | Prefix{} * Unit{};
  static std::string expexted() {
    return std::to_string(1) + " [" +
           std::string(prefix_<std::ratio_multiply<Prefix, std::kilo>>::str) +
           std::string(symbol_<typename basis_<Unit>::template type<0>>::str) +
           "]";
  }
};
TEST_CASE("prefix format tests", "[prefix]") {
  REQUIRE(prefix_<std::pico>::str == "p"s);
  REQUIRE(prefix_<std::nano>::str == "n"s);
  REQUIRE(prefix_<std::micro>::str == "u"s);
  REQUIRE(prefix_<std::milli>::str == "m"s);
  REQUIRE(prefix_<std::centi>::str == "c"s);
  REQUIRE(prefix_<std::deci>::str == "d"s);
  REQUIRE(prefix_<std::deca>::str == "da"s);
  REQUIRE(prefix_<std::hecto>::str == "h"s);
  REQUIRE(prefix_<std::kilo>::str == "k"s);
  REQUIRE(prefix_<std::mega>::str == "M"s);
  REQUIRE(prefix_<std::giga>::str == "G"s);
  REQUIRE(prefix_<std::tera>::str == "T"s);
}

TEST_CASE("symbol format tests", "[symbol]") {
  REQUIRE(symbol_<::mitama::length>::str == "m"s);
  REQUIRE(symbol_<electric_current>::str == "A"s);
  REQUIRE(symbol_<luminous_intensity>::str == "cd"s);
  REQUIRE(symbol_<thermodynamic_temperature>::str == "K"s);
  REQUIRE(symbol_<::mitama::mass>::str == "g"s);
  REQUIRE(symbol_<amount_of_substance>::str == "mol"s);
  REQUIRE(symbol_<::mitama::time>::str == "s"s);
}

TEMPLATE_TEST_CASE("meter_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, meter_t>::value) ==
          test_c<TestType, meter_t>::expexted());
}

TEMPLATE_TEST_CASE("ampere_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, ampere_t>::value) ==
          test_c<TestType, ampere_t>::expexted());
}

TEMPLATE_TEST_CASE("candela_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, candela_t>::value) ==
          test_c<TestType, candela_t>::expexted());
}

TEMPLATE_TEST_CASE("kelvin_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, kelvin_t>::value) ==
          test_c<TestType, kelvin_t>::expexted());
}

TEMPLATE_TEST_CASE("mol_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, mol_t>::value) ==
          test_c<TestType, mol_t>::expexted());
}

TEMPLATE_TEST_CASE("second_t format tests", "[quantity][symbol][prefix]",
                   std::pico, std::nano, std::micro, std::milli, std::centi,
                   std::deci, std::deca, std::hecto, std::kilo, std::mega,
                   std::giga, std::tera) {
  REQUIRE(fmt(test_c<TestType, second_t>::value) ==
          test_c<TestType, second_t>::expexted());
}

TEST_CASE("kilogram_t format tests", "[quantity][symbol][prefix]") {
  REQUIRE(fmt(1 | mega * kilograms) == "1 [Gg]");
  REQUIRE(fmt(1 | kilo * kilograms) == "1 [t]");
  REQUIRE(fmt(1 | kilograms) == "1 [kg]");
  REQUIRE(fmt(1 | milli * kilograms) == "1 [g]");
  REQUIRE(fmt(1 | micro * kilograms) == "1 [mg]");
}

TEST_CASE("hectare format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | hectare) == "1 [ha]");
}

TEST_CASE("litre format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | litre) == "1 [L]");
}

TEST_CASE("liter format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | liter) == "1 [L]");
}

TEST_CASE("tonne format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | tonne) == "1 [t]");
}

TEST_CASE("au format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | au) == "1 [au]");
}

TEST_CASE("minutes format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | minutes) == "1 [m]");
}

TEST_CASE("hours format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | hours) == "1 [h]");
}

TEST_CASE("days format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | days) == "1 [d]");
}

TEST_CASE("radian format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | radian) == "1 [rad]");
}

TEST_CASE("steradian format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | steradian) == "1 [sr]");
}

TEST_CASE("sievert format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | sievert) == "1 [Sv]");
}

TEST_CASE("becquerel format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | becquerel) == "1 [Bq]");
}

TEST_CASE("hertz  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | hertz) == "1 [Hz]");
}

TEST_CASE("newton  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | newton) == "1 [N]");
}

TEST_CASE("pascal  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | pascal) == "1 [Pa]");
}

TEST_CASE("joule  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | joule) == "1 [J]");
}

TEST_CASE("watt format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | watt) == "1 [W]");
}

TEST_CASE("coulomb  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | coulomb) == "1 [C]");
}

TEST_CASE("volt  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | volt<1>) == "1 [V]");
}

TEST_CASE("farad  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | farad) == "1 [F]");
}

TEST_CASE("ohm  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | ohm) == "1 [Ω]");
}

TEST_CASE("siemens  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | siemens) == "1 [S]");
}

TEST_CASE("weber  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | weber) == "1 [Wb]");
}

TEST_CASE("tesla  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | tesla) == "1 [T]");
}

TEST_CASE("henry  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | henry) == "1 [H]");
}

TEST_CASE("lumen  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | lumen) == "1 [lm]");
}

TEST_CASE("lux  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | lux) == "1 [lx]");
}

TEST_CASE("gray  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | gray) == "1 [Gy]");
}

TEST_CASE("katal  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | katal) == "1 [kat]");
}

TEST_CASE("velocity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | velocity) == "1 [m/s]");
}

TEST_CASE("speed format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | speed) == "1 [km/h]");
}

TEST_CASE("accelaration format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | accelaration) == fmt(1 | meter<>/second<2>));
}

TEST_CASE("jerk format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | jerk) == fmt(1 | meter<>/second<3>));
}

TEST_CASE("snap format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | snap) == fmt(1 | meter<>/second<4>));
}

TEST_CASE("crackle format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | crackle) == fmt(1 | meter<>/second<5>));
}

TEST_CASE("pop format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | pop) == fmt(1 | meter<>/second<6>));
}

TEST_CASE("frequency_drift format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | frequency_drift) == fmt(1 | second<-2>));
}

TEST_CASE("volumetric_flow format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | volumetric_flow) == fmt(1 | meter<3>/second<>));
}

TEST_CASE("area  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | area) == "1 [m^2]");
}

TEST_CASE("volume  format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | volume) == "1 [m^3]");
}

TEST_CASE("momentum format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | momentum) == "1 [m·kg·s^-1]");
}

TEST_CASE("impulse format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | impulse) == "1 [m·kg·s^-1]");
}

TEST_CASE("torque format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | torque) == "1 [J]");
}

TEST_CASE("wavenumber format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | wavenumber) == "1 [m^-1]");
}

TEST_CASE("optical_power format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | optical_power) == "1 [m^-1]");
}

TEST_CASE("curvature format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | curvature) == "1 [m^-1]");
}

TEST_CASE("spatial_frequency format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | spatial_frequency) == "1 [m^-1]");
}

TEST_CASE("area_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | area_density) == "1 [m^-2·kg]");
}

TEST_CASE("density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | density) == "1 [m^-3·kg]");
}

TEST_CASE("specific_volume format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | specific_volume) == "1 [m^3·kg^-1]");
}

TEST_CASE("action format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | action) == "1 [m^2·kg·s^-1]");
}

TEST_CASE("specific_energy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | specific_energy) == "1 [Gy]");
}

TEST_CASE("energy_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | energy_density) == "1 [Pa]");
}

TEST_CASE("surf_tension format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | surf_tension) == "1 [N/m]");
}

TEST_CASE("stiffness format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | stiffness) == "1 [N/m]");
}

TEST_CASE("heat_flux_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | heat_flux_density) == "1 [W/m]");
}

TEST_CASE("irradiance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | irradiance) == "1 [W/m]");
}

TEST_CASE("kinematic_viscosity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | kinematic_viscosity) == "1 [m^2/s]");
}

TEST_CASE("thermal_diffusivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | thermal_diffusivity) == "1 [m^2/s]");
}

TEST_CASE("linear_mass_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | linear_mass_density) == "1 [m^-1·kg]");
}

TEST_CASE("mass_flow_rate format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | mass_flow_rate) == "1 [kg·s^-1]");
}

TEST_CASE("radiance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | radiance) == "1 [W/(sr·m^2)]");
}

TEST_CASE("spectral_radiance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | spectral_radiance) == "1 [W/(sr·m^3)]");
}

TEST_CASE("spectral_power format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | spectral_power) == "1 [W/m]");
}

TEST_CASE("absorbed_dose_rate format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | absorbed_dose_rate) == "1 [Gy/s]");
}

TEST_CASE("fuel_efficiency format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | fuel_efficiency) == "1 [m^-2]");
}

TEST_CASE("spectral_irradiance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | spectral_irradiance) == "1 [W/m^3]");
}

TEST_CASE("power_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | power_density) == "1 [W/m^3]");
}

TEST_CASE("energy_flux_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | energy_flux_density) == "1 [W/m^2]");
}

TEST_CASE("compressibility format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | compressibility) == "1 [Pa^-1]");
}

TEST_CASE("radiant_exposure format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | radiant_exposure) == "1 [N/m]");
}

TEST_CASE("moment_of_inertia format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | moment_of_inertia) == "1 [kg·m^2]");
}

TEST_CASE("specific_angular_momentum format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | specific_angular_momentum) == "1 [m^2/s]");
}

TEST_CASE("radiant_intensity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | radiant_intensity) == "1 [W/sr]");
}

TEST_CASE("spectral_intensity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | spectral_intensity) == "1 [W/(sr·m)]");
}

TEST_CASE("dynamic_viscosity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | dynamic_viscosity) == "1 [Pa·s]");
}

TEST_CASE("angular_velocity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | angular_velocity) == "1 [rad/s]");
}

TEST_CASE("angular_accelaration format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | angular_accelaration) == "1 [rad/s^2]");
}

TEST_CASE("molarity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | molarity) == "1 [mol/m^3]");
}

TEST_CASE("molar_volume format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | molar_volume) == "1 [m^3/mol]");
}

TEST_CASE("molar_heat_capacity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | molar_heat_capacity) == "1 [J/(K·mol)]");
}

TEST_CASE("molar_entropy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | molar_entropy) == "1 [J/(K·mol)]");
}

TEST_CASE("molar_energy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | molar_energy) == "1 [J/mol]");
}

TEST_CASE("molar_conductivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | molar_conductivity) == "1 [S·m^2/mol]");
}

TEST_CASE("molality format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | molality) == "1 [mol/kg]");
}

TEST_CASE("molar_mass format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | molar_mass) == "1 [kg/mol]");
}

TEST_CASE("catalytic_efficiency format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | catalytic_efficiency) == "1 [m^3/(mol·s)]");
}

TEST_CASE("electric_displacement_field format test",
          "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | electric_displacement_field) == "1 [C/m^2]");
}

TEST_CASE("polarization_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | polarization_density) == "1 [C/m^2]");
}

TEST_CASE("electric_charge_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | electric_charge_density) == "1 [C/m^3]");
}

TEST_CASE("charge_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | charge_density) == "1 [C/m^3]");
}

TEST_CASE("electric_current_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | electric_current_density) == "1 [A/m^2]");
}

TEST_CASE("electrical_conductivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | electrical_conductivity) == "1 [S/m]");
}

TEST_CASE("permittivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | permittivity) == "1 [F/m]");
}

TEST_CASE("permeability format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | permeability) == "1 [H/m]");
}

TEST_CASE("electric_field_strength format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | electric_field_strength) == "1 [V/m]");
}

TEST_CASE("magnetization format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetization) == "1 [A/m]");
}

TEST_CASE("magnetic_field_strength format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetic_field_strength) == "1 [A/m]");
}

TEST_CASE("exposure format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | exposure) == "1 [C/kg]");
}

TEST_CASE("resistivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | resistivity) == "1 [Ω·m]");
}

TEST_CASE("linear_charge_density format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | linear_charge_density) == "1 [C/m]");
}

TEST_CASE("magnetic_dipole_moment format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetic_dipole_moment) == "1 [m^2·A]");
}

TEST_CASE("electron_mobility format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | electron_mobility) == "1 [m^2/(V·s)]");
}

TEST_CASE("magnetic_reluctance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetic_reluctance) == "1 [H^-1]");
}

TEST_CASE("magnetic_vector_potential format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetic_vector_potential) == "1 [Wb/m]");
}

TEST_CASE("magnetic_moment format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetic_moment) == "1 [Wb·m]");
}

TEST_CASE("magnetic_rigidity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetic_rigidity) == "1 [T·m]");
}

TEST_CASE("magnetomotive_force format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetomotive_force) == "1 [A·rad]");
}

TEST_CASE("magnetic_susceptibility format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | magnetic_susceptibility) == "1 [m/H]");
}

TEST_CASE("luminous_energy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | luminous_energy) == "1 [lm·s]");
}

TEST_CASE("luminous_exposure format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | luminous_exposure) == "1 [lx·s]");
}

TEST_CASE("luminance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | luminance) == "1 [lx·s]");
}

TEST_CASE("luminous_efficacy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | luminous_efficacy) == "1 [lm/W]");
}

TEST_CASE("heat_capacity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | heat_capacity) == "1 [J/K]");
}

TEST_CASE("entropy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | entropy) == "1 [J/K]");
}

TEST_CASE("specific_heat_capacity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | specific_heat_capacity) == "1 [J/(kg·K)]");
}

TEST_CASE("specific_entropy format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | specific_entropy) == "1 [J/(kg·K)]");
}

TEST_CASE("thermal_conductivity format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | thermal_conductivity) == "1 [W/(m·K)]");
}

TEST_CASE("heat_flux format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | heat_flux) == "1 [W/m^2]");
}

TEST_CASE("thermal_resistance format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | thermal_resistance) == "1 [K/W]");
}

TEST_CASE("thermal_expansion_coefficient format test",
          "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | thermal_expansion_coefficient) == "1 [K^-1]");
}

TEST_CASE("temperature_gradient format test", "[quantity][abbreviation]") {
  REQUIRE(fmt(1 | temperature_gradient) == "1 [K·m^-1]");
}
