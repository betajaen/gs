#include <proto/exec.h>
#include <proto/dos.h>
#include <gs/util/memory.hpp>

namespace gs {
    enum class return_code_t : LONG;

    BPTR cli_output = 0;

    #if defined(gs_debug_memory) && gs_debug_memory == 1
    namespace util {
        void debug_allocations();
    }
    #endif

    return_code_t entry();

    static inline int gs_main(void) {
        cli_output = Output();
        return_code_t rv = gs::entry();

        return (int) rv;
    }

}

int main(void) {
    return gs::gs_main();
}