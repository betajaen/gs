#include <proto/exec.h>
#include <proto/dos.h>
#include <gs/util/memory.hpp>

namespace gs {
    BPTR cli_output = 0;
    int entry();
}

int main(void) {
    gs::cli_output = Output();

    int rv = gs::entry();
#if defined(gs_debug_memory) && gs_debug_memory == 1
    gs::util::debug_allocations();
#endif

    return rv;
}