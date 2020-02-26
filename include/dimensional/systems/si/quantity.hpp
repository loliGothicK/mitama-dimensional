#ifndef MITAMA_DIMENSIONAL_SYSTEMS_SI_QUANTITY_HPP
#define MITAMA_DIMENSIONAL_SYSTEMS_SI_QUANTITY_HPP
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/base_units/fwd/si_base_units.hpp>

namespace mitama::systems::si {
  template < class D, typename T = double > 
  using quantity_t
    = ::mitama::quantity_t<D, T, ::mitama::systems::si::system>;
}

#endif // !MITAMA_DIMENSIONAL_SYSTEMS_SI_QUANTITY_HPP
