#pragma once

#include <gs/util/types.hpp>
#include <gs/util/pod_variant.hpp>

namespace gs::hw {
    struct start_param_t {
        uint32_t code;
        util::pod_variant_t param;

        void parse_from_entry();
    };

    extern start_param_t g_start_param;
}
