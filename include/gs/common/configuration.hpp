#pragma once

#include <gs/util/types.hpp>
#include <gs/util/pod_variant.hpp>

namespace gs::common {
    struct configuration_t {
        uint32_t start_param;

        void parse_from_entry();
    };

    extern configuration_t g_configuration;
}
