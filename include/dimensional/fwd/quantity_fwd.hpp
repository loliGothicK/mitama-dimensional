#ifndef MITAMA_DIMENSIONAL_FWD_QUANTITY_FWD_HPP
#define MITAMA_DIMENSIONAL_FWD_QUANTITY_FWD_HPP
#include <dimensional/fwd/system.hpp>

namespace mitama {

    template < class, auto >
    struct static_quantity_t;

    template < template < auto > class, class >
    class refined;

    template < class, class = double, class = system<> >
    class quantity_t;

    template <class, class> struct converter;
}
#endif
