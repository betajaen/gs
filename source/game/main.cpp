#include <gs/util/types.hpp>
#include <gs/util/debug.hpp>

namespace gs {
    int entry() {
        gs::info_fmt("gs %s", gs_version);
        return 0;
    }
}