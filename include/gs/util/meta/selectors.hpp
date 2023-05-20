#pragma once

#include "gs/util/pod.hpp"
#include "gs/util/meta/equality.hpp"

namespace gs::util::meta {

    template<typename T, typename T0>
    constexpr size_t index_of() {
        if (same<T, T0>()) {
            return 0;
        }
        else {
            return 1;
        }
    }

}