#include <proto/exec.h>
#include <proto/dos.h>
#include <gs/util/memory.hpp>
#include <gs/util/debug.hpp>
#include <gs/hw/start_param.hpp>


namespace gs {
    enum class return_code_t : LONG;

    BPTR g_cli_output = 0;

    #if defined(gs_debug_memory) && gs_debug_memory == 1
    namespace util {
        void debug_allocations();
    }
    #endif

    return_code_t entry();

    static inline int gs_main(void) {
        g_cli_output = Output();

        hw::g_start_param.parse_from_entry();
        return_code_t rv = gs::entry();

        return (int) rv;
    }

}

int main(void) {
    return gs::gs_main();
}