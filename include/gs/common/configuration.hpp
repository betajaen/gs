#pragma once

#include <gs/system/pod.hpp>

namespace gs::common {
    struct configuration_t {
        uint32_t start_param;

        void parse_from_entry();
    };

    extern configuration_t g_configuration;
}
