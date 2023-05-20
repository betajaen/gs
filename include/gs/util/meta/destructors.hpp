#pragma once

#include "gs/util/pod.hpp"

namespace gs::util::meta {

    template<typename T0>
    void delete_from(size_t N, void* data) {
        if (N == 0) {
            ((T0*)(data))->~T0();
        }
    }

}