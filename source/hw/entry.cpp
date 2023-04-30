#include <gs/util/debug.hpp>

#include <proto/exec.h>
#include <proto/dos.h>
#include <clib/debug_protos.h>

namespace gs::hw {
    BPTR cli_output = 0;
}


int main(void) {
    gs::hw::cli_output = Output();

    gs::info_fmt("goodsoup %s", gs_version);
    return RETURN_OK;
}