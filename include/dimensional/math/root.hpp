#ifndef MITAMA_DIMENSIONAL_MATH_ROOT_HPP
#define MITAMA_DIMENSIONAL_MATH_ROOT_HPP

#include <cmath>
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/meter.hpp>
namespace mitama {

template < template <class> class Synonym, class T, class... Units >
auto sqrt(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<1, 2>>::type>, T>
        {
            static_cast<T>(std::sqrt(quantity.value()))
        };
}


template < template <class> class Synonym, class T, class... Units >
auto cbrt(quantity_t<Synonym<dimensional_t<Units...>>, T> const& quantity) {
    return quantity_t<Synonym<typename mitamagic::powered_dimensional<dimensional_t<Units...>, std::ratio<1, 3>>::type>, T>
        {
            static_cast<T>(std::cbrt(quantity.value()))
        };
}

template < class... Quantities,
    std::enable_if_t<(sizeof...(Quantities) == 2 || sizeof...(Quantities) == 3)
                  && std::conjunction_v<::mitama::is_same_dimensional<Quantities, ::mitama::quantity<::mitama::systems::si::meter_t>>...>,
                bool> = false>
auto hypot(Quantities... quantities) {
    return ::mitama::common_type_t<std::decay_t<Quantities>...>{ std::hypot(static_cast<::mitama::common_type_t<std::decay_t<Quantities>...>>(quantities).value()...) };
}

}

#endif