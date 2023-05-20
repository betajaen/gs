#pragma once

#include <gs/util/pod.hpp>

namespace gs::util::meta {

    template<typename T0>
    constexpr size_t size_of() {
        return sizeof(T0);
    }

    template<typename T0, typename T1>
    constexpr size_t size_of() {
        return sizeof(T0) > sizeof(T1) ? sizeof(T0) : sizeof(T1);
    }

    template<typename T0>
    constexpr size_t count() {
        return 1;
    }

}