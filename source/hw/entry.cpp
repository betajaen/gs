#include <proto/exec.h>
#include <proto/dos.h>

namespace gs {
    BPTR cli_output = 0;

    int entry();
}

int main(void) {
    gs::cli_output = Output();
    return gs::entry();
}