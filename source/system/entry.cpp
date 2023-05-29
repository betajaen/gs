#include <proto/exec.h>
#include <proto/dos.h>
#include <gs/util/memory.hpp>
#include <gs/common/configuration.hpp>


namespace gs {
    enum class return_code_t : LONG;

    #if defined(gs_debug_memory) && gs_debug_memory == 1
    namespace util {
        void debug_allocations();
    }
    #endif

    return_code_t entry();

    int main() {

        common::g_configuration.parse_from_entry();
        return_code_t rv = gs::entry();

        return (int) rv;
    }

}
