#include <gs/system/memory.hpp>
#include <gs/common/configuration.hpp>

#include <proto/exec.h>
#include <proto/dos.h>

namespace gs {
    enum class ReturnCode : LONG;

    #if defined(GS_DEBUG_MEMORY) && GS_DEBUG_MEMORY == 1
    namespace util {
        void DebugCurrentAllocations();
    }
    #endif

    ReturnCode entry();

    int main() {

        common::Configuration::s_Instance.ParseFromEntry();
        ReturnCode rv = gs::entry();

        return (int) rv;
    }

}
