#include <dimensional/quantity.hpp>

namespace mitama {
    // base dimension type
    struct wizarding_currency {
        // meta tag
        using is_base_dimension = void;
    };
    // base unit
    using knut_t = make_units_t<wizarding_currency>;
    // scaled unit
    using sickle_t = scaled_unit_t<knut_t, std::ratio<29>>;
    // scaled unit
    using galleon_t = scaled_unit_t<knut_t, std::ratio<17>>;

    inline constexpr knut_t knuts{};
    inline constexpr knut_t knut{};

    inline constexpr sickle_t sickles{};
    inline constexpr sickle_t sickle{};

    inline constexpr galleon_t galleons{};
    inline constexpr galleon_t galleon{};
}