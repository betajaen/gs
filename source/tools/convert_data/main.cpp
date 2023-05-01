#include <gs/util/types.hpp>
#include <gs/util/debug.hpp>
#include <gs/enums/return_code.hpp>

namespace gs {
    return_code_t entry() {
        gs::info_fmt("gs-convert-data %s", gs_version);
        return return_code_t::Ok;
    }
}