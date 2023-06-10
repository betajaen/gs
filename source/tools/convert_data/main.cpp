#include <gs/system/pod.hpp>
#include <gs/enums/return_code.hpp>
#include <gs/system/debug.hpp>

namespace gs {
    ReturnCode entry() {
        INFO_FMT("gs-convert-data %s", GS_VERSION);
        return ReturnCode::OK;
    }
}