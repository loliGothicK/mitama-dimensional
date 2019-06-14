
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
/*
Here's an example how to implement user extension dimensions
by taking the currency of the wizarding world of Harry Potter.
*/
namespace wizarding {
    // (1) - define base dimension type.
    struct wizarding_currency {
        // required: meta tag type `is_base_dimension`
        using is_base_dimension = void;
    };
    // (2) - define base unit type using `mitama::make_unit_t`.
    using knut_t = mitama::make_unit_t<wizarding_currency>;
    // (3) - define scaled unit aliasing using `mitama::scaled_unit_t<UnitType, Ratio>`.
    // [ - Note:
    //     In Wizarding World of Harry Potter, 1 sickle = 29 knuts and 1 galleon = 17 sickles.
    //   - end note ]
    using sickle_t = mitama::scaled_unit_t<knut_t, std::ratio<29>>;
    using galleon_t = mitama::scaled_unit_t<sickle_t, std::ratio<17>>;

    // (4) - define inline constexpr variables [optional].
    // for operator |
    // [ - Example:
    //     auto x = 42 | knuts; // x: quantity_t<knut_t, int>
    //   - end example ]
    inline constexpr knut_t knuts{};
    inline constexpr knut_t knut{};

    inline constexpr sickle_t sickles{};
    inline constexpr sickle_t sickle{};

    inline constexpr galleon_t galleons{};
    inline constexpr galleon_t galleon{};
}

namespace mitama {
    // (5) - define partial specialization class `abbreviation` for pretty printing [optional].
    template <> struct abbreviation_<wizarding::knut_t> { static constexpr char str[] = "knuts"; };
    template <> struct abbreviation_<wizarding::sickle_t> { static constexpr char str[] = "sickles"; };
    template <> struct abbreviation_<wizarding::galleon_t> { static constexpr char str[] = "galleons"; };
}