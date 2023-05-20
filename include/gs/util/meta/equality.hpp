#pragma once

namespace gs::util::meta {

    template<typename T>
    constexpr T max(T lhs, T rhs) {
        return lhs > rhs ? lhs : rhs;
    }

    template<typename T>
    constexpr T min(T lhs, T rhs) {
        return lhs < rhs ? lhs : rhs;
    }

    template<typename T>
    constexpr T equals(T lhs, T rhs) {
        return lhs == rhs;
    }

    template<typename T>
    constexpr T not_equals(T lhs, T rhs) {
        return lhs != rhs;
    }

    namespace impl {
        template<typename T0, typename T1>
        struct same_impl { static constexpr bool value = false; };

        template<typename T>
        struct same_impl<T, T> { static constexpr bool value = true; };
    }

    template<typename T0, typename T1>
    constexpr bool same() {
        return impl::same_impl<T0, T1>::value;
    }

    template<typename T, typename T0>
    constexpr bool any_of() {
        if (same<T, T0>() == true) {
            return true;
        }

        return false;
    }

}