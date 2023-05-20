#pragma once

#include <gs/util/pod.hpp>
#include <gs/util/meta/equality.hpp>
#include <new>

namespace gs::util::meta {

    template<size_t N, typename T0>
    size_t construct_into(void* data) {
        if (N == 0) {
            new(data) T0();
            return 0;
        }
        else {
            return 1;
        }
    }

    template<typename T0>
    size_t construct_into(size_t n, void* data) {
        if (n == 0) {
            new(data) T0();
            return 0;
        }
        else {
            return 1;
        }
    }
    template<typename T, typename T0>
    size_t construct_into(const T& value, void* data) {
        if (same<T, T0>()) {
            new(data) T0();
            return 0;
        }
        else {
            return 1;
        }
    }


}