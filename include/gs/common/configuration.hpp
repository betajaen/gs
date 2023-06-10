#pragma once

#include <gs/system/pod.hpp>

namespace gs::common {
    struct Configuration {
        static Configuration s_Instance;
        uint32_t m_StartParam;

        void ParseFromEntry();
    };

}
