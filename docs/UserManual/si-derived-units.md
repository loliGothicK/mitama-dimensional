# Library defined units and format
--------------------------------


## Format IO

`std::ostream` adaptor `operator <<` is defined in header [`<dimensional/io.hpp>`]().

**example**

```cpp
// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/si_units/all.hpp>
#include <dimensional/io.hpp>

int main() {
    using mitama::quantity_t;
    namespace si = mitama::si;

    quantity_t a = 1 | si::meters;

    std::cout << a << '\n'; // 1 [m]
}
// end example
```

## SI basic units

| type name <br> quantifier name | Unit symbol |  Quantity measured  |
| :----------------------------: | :---------: | :-----------------: |
| metre_t/meter_t<br>metre/meter |      m      |       length        |
|     kilogram_t<br>kilogram     |     kg      |        mass         |
|       second_t<br>second       |      s      |        time         |
|       ampere_t<br>ampere       |      A      |  electric current   |
|       kelvin_t<br>kelvin       |      K      |     temperature     |
|         mole_t<br>mole         |     mol     | amount of substance |
|      candela_t<br>candela      |     cd      | luminous intensity  |

## Non SI units

| type name <br> quantifier name | Unit symbol | Equivalents in termsof SI units |
| :----------------------------: | :---------: | :-----------------------------: |
|      hectare_t<br>hectare      |     ha      |       $$1\ ha = 10^4\ m^2$$       |
| litre_t/liter_t<br>litre/liter |      L      |      $$1\ L = 10^{-3}\ m^3$$      |
|        tonne_t<br>tonne        |      t      |        $$1\ t = 10^3\ kg$$        |
|           au_t<br>au           |      t      |  $$1\ au = 149,597,870,700\ m$$   |
|      minute_t<br>minutes       |     min     |        $$1 min = 60\ s$$         |
|        hour_t<br>hours         |      h      |    $$1\ h = 60\ min = 3600 s$$    |
|         day_t<br>days          |      h      |    $$1\ d = 24\ h = 86400 s$$     |


## Named units derived from SI base units

|   type name <br> quantifier Name   |   Symbol   |                    Quantity                     |                     Equivalents                      |           SI base unit Equivalents           |
| :--------------------------------: | :--------: | :---------------------------------------------: | :--------------------------------------------------: | :------------------------------------------: |
|          hertz_t<br>hertz          |     Hz     |                    frequency                    |                       $$1/s$$                        |                  $$s^{-1}$$                  |
|         radian_t<br>radian         |    rad     |                      angle                      |                       $$m/m$$                        |                    $$1$$                     |
|      steradian_t<br>steradian      |     sr     |                   solid angle                   |                     $$m^2/m^2$$                      |                    $$1$$                     |
|         newton_t<br>newton         |     N      |                force <br> weight                |                  $$kg \cdot m/s^2$$                  |         $$kg \cdot m \cdot s^{-2}$$          |
|         pascal_t<br>pascal         |     Pa     |              pressure <br> stress               |                      $$N/m^2$$                       |       $$kg \cdot m^{-1} \cdot s^{-2}$$       |
|          joule_t<br>joule          |     J      |           energy <br> work <br> heat            |   $$N \cdot m \\ C \cdot V \\ W \cdot s$$    |        $$kg \cdot m^2 \cdot s^{-2}$$         |
|           watt_t<br>watt           |     W      |             power <br> radiant flux             |               $$J/s \\ V \cdot A$$               |        $$kg \cdot m^2 \cdot s^{-3}$$         |
|        coulomb_t<br>coulomb        |     C      |  electric charge <br> quantity of electricity   |            $$s \cdot A \\ F \cdot V$$            |                $$s \cdot A$$                 |
|           volt_t<br>volt           |     V      |  voltage <br> electrical potential difference   |                  $$W/A \\ J/C$$                  |  $$kg \cdot m^2 \cdot s^{-3} \cdot A^{-1}$$  |
|          farad_t<br>farad          |     F      |             electrical capacitance              |               $$C/V \\ s/\Omega$$                | $$kg^{-1} \cdot m^{-2} \cdot s^4 \cdot A^2$$ |
|            ohm_t<br>ohm            | $$\Omega$$ | electrical resistance <br> impedance, reactance |                  $$1/S \\ V/A$$                  |  $$kg \cdot m^2 \cdot s^{-3} \cdot A^{-2}$$  |
|        siemens_t<br>siemens        |     S      |             electrical conductance              |               $$1/\Omega \\ A/V$$                | $$kg^{-1} \cdot m^{-2} \cdot s^3 \cdot A^2$$ |
|          weber_t<br>weber          |     Wb     |                  magnetic flux                  |              $$J/A \\ T \cdot m^2$$              |  $$kg \cdot m^2 \cdot s^{-2} \cdot A^{-1}$$  |
|          tesla_t<br>tesla          |     T      |  magnetic induction <br> magnetic flux density  | $$V \cdot s/m^2 \\ Wb/m^2 \\ N/(A \cdot m)$$ |       $$kg \cdot s^{-2} \cdot A^{-1}$$       |
|          henry_t<br>henry          |     H      |              electrical inductance              |  $$V \cdot s/A \\ \Omega \cdot s \\ Wb/A$$   |  $$kg \cdot m^2 \cdot s^{-2} \cdot A^{-2}$$  |
| degree_celsius_t<br>degree_celsius |     °C     |        temperature relative to 273.15 K         |                        $$K$$                         |                    $$K$$                     |
|          lumen_t<br>lumen          |     lm     |                  luminous flux                  |                   $$cd \cdot sr$$                    |                    $$cd$$                    |
|            lux_t<br>lux            |     lx     |                   illuminance                   |                      $$lm/m^2$$                      |             $$m^{-2} \cdot cd$$              |
|      becquerel_t<br>becquerel      |     Bq     |    radioactivity <br> (decays per unit time)    |                       $$1/s$$                        |                  $$s^{-1}$$                  |
|           gray_t<br>gray           |     Gy     |   absorbed dose <br> (of ionizing radiation)    |                       $$J/kg$$                       |             $$m^2 \cdot s^{-2}$$             |
|        sievert_t<br>sievert        |     Sv     |  equivalent dose <br> (of ionizing radiation)   |                       $$J/kg$$                       |             $$m^2 \cdot s^{-2}$$             |
|          katal_t<br>katal          |    kat     |               catalytic activity                |                      $$mol/s$$                       |             $$s^{-1} \cdot mol$$             |

## Kinematic SI derived units

|         type name <br> quantifier Name         |   Symbol    | Expression in termsof SI base units |
| :--------------------------------------------: | :---------: | :---------------------------------: |
|             velocity_t<br>velocity             |   $$m/s$$   |         $$m \cdot s^{-1}$$          |
|         acceleration_t<br>acceleration         |  $$m/s^2$$  |         $$m \cdot s^{-2}$$          |
|                 jerk_t<br>jerk                 |  $$m/s^3$$  |         $$m \cdot s^{-3}$$          |
|                 snap_t<br>snap                 |  $$m/s^4$$  |         $$m \cdot s^{-4}$$          |
|              crackle_t<br>crackle              |  $$m/s^5$$  |         $$m \cdot s^{-5}$$          |
|                  pop_t<br>pop                  |  $$m/s^6$$  |         $$m \cdot s^{-6}$$          |
|     angular_velocity_t<br>angular_velocity     |  $$rad/s$$  |             $$s^{-1}$$              |
| angular_acceleration_t<br>angular_acceleration | $$rad/s^2$$ |             $$s^{-2}$$              |
|      frequency_drift_t<br>frequency_drift      |  $$Hz/s$$   |             $$s^{-2}$$              |
|      volumetric_flow_t<br>volumetric_flow      |  $$m^3/s$$  |        $$m^3 \cdot s^{-1}$$         |

## Molar SI derived units

|         type name <br> quantifier Name         |        Symbol         |           Expression in terms of SI base units            |
| :--------------------------------------------: | :-------------------: | :-------------------------------------------------------: |
|             molarity_t<br>molarity             |      $$mol/m^3$$      |                   $$m^{-3} \cdot mol$$                    |
|        molar_volume_t<br>molar_volume_t        |      $$m^3/mol$$      |                  $$m^3 \cdot mol^{-1}$$                   |
|        molar_entropy_t<br>molar_entropy        |  $$J/(K \cdot mol)$$  | $$m^2 \cdot kg \cdot s^{-2} \cdot K^{-1} \cdot mol^{-1}$$ |
|  molar_heat_capacity_t<br>molar_heat_capacity  |  $$J/(K \cdot mol)$$  | $$m^2 \cdot kg \cdot s^{-2} \cdot K^{-1} \cdot mol^{-1}$$ |
|         molar_energy_t<br>molar_energy         |       $$J/mol$$       |       $$m^2 \cdot kg \cdot s^{-2} \cdot mol^{-1}$$        |
|   molar_conductivity_t<br>molar_conductivity   |  $$S \cdot m^2/mol$$  |      $$kg^{-1} \cdot s^3 \cdot A^2 \cdot mol^{-1}$$       |
|             molality_t<br>molality             |      $$mol/kg$$       |                   $$kg^{-1} \cdot mol$$                   |
|           molar_mass_t<br>molar_mass           |      $$kg/mol$$       |                   $$kg \cdot mol^{-1}$$                   |
| catalytic_efficiency_t<br>catalytic_efficiency | $$m^3/(mol \cdot s)$$ |            $$m^3 \cdot s^{-1} \cdot mol^{-1}$$            |

## Electromagnetic SI derived units

|                type name <br> quantifier Name                |       Symbol        |     Expression in terms of SI base units     |
| :----------------------------------------------------------: | :-----------------: | :------------------------------------------: |
| electric_displacement_field_t<br>electric_displacement_field |      $$C/m^2$$      |          $$m^{-2} \cdot s \cdot A$$          |
|        polarization_density_t<br>polarization_density        |         ---         |          $$m^{-2} \cdot s \cdot A$$          |
|     electric_charge_density_t<br>electric_charge_density     |      $$C/m^3$$      |          $$m^{-3} \cdot s \cdot A$$          |
|    electric_current_density_t<br>electric_current_density    |      $$A/m^2$$      |              $$m^{-2} \cdot A$$              |
|     electrical_conductivity_t<br>electrical_conductivity     |       $$S/m$$       | $$m^{-3} \cdot kg^{-1} \cdot s^3 \cdot A^2$$ |
|                permittivity_t<br>permittivity                |       $$F/m$$       | $$m^{-3} \cdot kg^{-1} \cdot s^4 \cdot A^2$$ |
|                permeability_t<br>permeability                |       $$H/m$$       |   $$m \cdot kg \cdot s^{-2} \cdot A^{-2}$$   |
|     electric_field_strength_t<br>electric_field_strength     |       $$V/m$$       |   $$m \cdot kg \cdot s^{-3} \cdot A^{-1}$$   |
|               magnetization_t<br>magnetization               |       $$A/m$$       |              $$m^{-1} \cdot A$$              |
|                    exposure_t<br>exposure                    |      $$C/kg$$       |         $$kg^{-1} \cdot s \cdot A$$          |
|                 resistivity_t<br>resistivity                 | $$\Omega \cdot m$$  |  $$m^3 \cdot kg \cdot s^{-3} \cdot A^{-2}$$  |
|       linear_charge_density_t<br>linear_charge_density       |       $$C/m$$       |          $$m^{-1} \cdot s \cdot A$$          |
|      magnetic_dipole_moment_t<br>magnetic_dipole_moment      |         ---         |               $$m^2 \cdot A$$                |
|           electron_mobility_t<br>electron_mobility           | $$m^2/(V \cdot s)$$ |        $$kg^{-1} \cdot s^2 \cdot A$$         |
|         magnetic_reluctance_t<br>magnetic_reluctance         |     $$H^{-1}$$      | $$m^{-2} \cdot kg^{-1} \cdot s^2 \cdot A^2$$ |
|   magnetic_vector_potential_t<br>magnetic_vector_potential   |      $$Wb/m$$       |   $$m \cdot kg \cdot s^{-2} \cdot A^{-1}$$   |
|             magnetic_moment_t<br>magnetic_moment             |   $$Wb \cdot m$$    |  $$m^3 \cdot kg \cdot s^{-2} \cdot A^{-1}$$  |
|           magnetic_rigidity_t<br>magnetic_rigidity           |    $$T \cdot m$$    |   $$m \cdot kg \cdot s^{-2} \cdot A^{-1}$$   |
|         magnetomotive_force_t<br>magnetomotive_force         |         ---         |                    $$A$$                     |
|     magnetic_susceptibility_t<br>magnetic_susceptibility     |       $$m/H$$       | $$m^{-1} \cdot kg^{-1} \cdot s^2 \cdot A^2$$ |

## Photometric SI derived units

|     type name <br> quantifier Name     |     Symbol     |         Expression in terms of SI base units         |
| :------------------------------------: | :------------: | :--------------------------------------------------: |
|  luminous_energy_t<br>luminous_energy  | $$lm \cdot s$$ |               $$s \cdot cd \cdot sr$$                |
| luminous_exposure_t<br>luminous_energy | $$lx \cdot s$$ |         $$m^{-2} \cdot s \cdot cd \cdot sr$$         |
|     luminance_t<br>luminous_energy     |   $$cd/m^2$$   |                 $$m^{-2} \cdot cd$$                  |
| luminous_efficacy_t<br>luminous_energy |    $$lm/W$$    | $$m^{-2} \cdot kg^{-1} \cdot s^3 \cdot cd \cdot sr$$ |


## Thermodynamic SI derived units

|                  type name <br> quantifier Name                  |       Symbol       |    Expression in terms of SI base units    |
| :--------------------------------------------------------------: | :----------------: | :----------------------------------------: |
|               heat_capacity_t<br>specific_entropy                |      $$J/K$$       | $$m^2 \cdot kg \cdot s^{-2} \cdot K^{-1}$$ |
|                       entropy_t<br>entropy                       |      $$J/K$$       | $$m^2 \cdot kg \cdot s^{-2} \cdot K^{-1}$$ |
|        specific_heat_capacity_t<br>specific_heat_capacity        | $$J/(K \cdot kg)$$ |     $$m^2 \cdot s^{-2} \cdot K^{-1}$$      |
|              specific_entropy_t<br>specific_entropy              | $$J/(K \cdot kg)$$ |     $$m^2 \cdot s^{-2} \cdot K^{-1}$$      |
|          thermal_conductivity_t<br>thermal_conductivity          | $$W/(m \cdot K)$$  |  $$m \cdot kg \cdot s^{-3} \cdot K^{-1}$$  |
|            thermal_resistance_t<br>thermal_resistance            |      $$K/W$$       | $$m^{-2} \cdot kg^{-1} \cdot s^3 \cdot K$$ |
| thermal_expansion_coefficient_t<br>thermal_expansion_coefficient |     $$K^{-1}$$     |                 $$K^{-1}$$                 |
|          temperature_gradient_t<br>temperature_gradient          |      $$K/m$$       |             $$m^{-1} \cdot K$$             |
