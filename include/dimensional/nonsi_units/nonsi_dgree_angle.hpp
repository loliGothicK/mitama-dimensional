#include "../quantity.hpp"
#include "../derived_units/named_units.hpp"

namespace mitama {

namespace nonsi {
struct dgree_angle_c { using is_base_dimension = void;};
}

template <> struct symbol_<::mitama::nonsi::dgree_angle_c> {
  static constexpr char str[] = "°";
};

using dgree_angle_t = make_unit_t<nonsi::dgree_angle_c>;

inline constexpr dgree_angle_t dgree_angle{};

template <class From, class To>
struct converter<quantity_t<radian_t, From>,
                 quantity_t<dgree_angle_t, To>>
{
    static constexpr To convert(quantity_t<radian_t, From> const& c)
        { return static_cast<To>(c.get() * 57.2957795130823208767l ); }
};
template <class From, class To>
struct converter<quantity_t<dgree_angle_t, From>,
                 quantity_t<radian_t, To>>
{
    static constexpr To convert(quantity_t<dgree_angle_t, From> const& s)
        { return static_cast<To>(s.get() / 57.2957795130823208767l ); }
};


} 
