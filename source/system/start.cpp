#include <proto/exec.h>
#include <proto/dos.h>
#include <gs/system/debug.hpp>

int __initlibraries=0;

struct DosLibrary* DOSBase = nullptr;

namespace gs {
    int main();
}

int main() {
    int rv;

    if (SysBase == nullptr) {
        SysBase = (ExecBase*) (*((struct Library **) 4));
        WARN_STR("SysBase is null!");
        return RETURN_FAIL;
    }

    DOSBase = (struct DosLibrary*) OpenLibrary("dos.library", 0);

    if (DOSBase == nullptr) {
        ERROR_STR("Could not open dos.library!");
        return RETURN_FAIL;
    }

    INFO_FMT("Goodsoup %s.", GS_VERSION);

    rv = gs::main();

    exit_function:

    CloseLibrary((Library*) DOSBase);
    DOSBase = nullptr;

    return rv;
}