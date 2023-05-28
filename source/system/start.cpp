#include <proto/exec.h>
#include <proto/dos.h>
#include <gs/system/debugger.hpp>

int __initlibraries=0;

struct DosLibrary* DOSBase = nullptr;

extern int gs_main();

int main() {

    if (SysBase == nullptr) {
        ERROR_STR("SysBase is null!");
        return RETURN_FAIL;
    }

    DOSBase = (struct DosLibrary*) OpenLibrary("dos.library", 0);

    if (DOSBase == nullptr) {
        ERROR_STR("Could not open dos.library!");
        return RETURN_FAIL;
    }

    INFO_STR("Goodsoup.");

    CloseLibrary((Library*) DOSBase);
    DOSBase = nullptr;

    return 0;
}